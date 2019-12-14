#include "MCTStree.h"

// board utilities :
//	just_play_color : get the last move player
//	addbp : add a black move to its log
//	addwp : add a white move to its log
//	add : do a black/white move on board
void MCTStree::select(board &b)
{
	
	// bool who = ! b.just_play_color();	//no needed
	ucbnode* nodeptr = root;
	b.bpsize=0;
	b.wpsize=0;
	path.clear();
	path.push_back(nodeptr);

	while(nodeptr->csize != 0)
	{
		nodeptr = nodeptr->get_bestchild();
		path.push_back(nodeptr);
	
		// no change, board subrutine
		// we add the info. to board for RAVE lookup
		if(nodeptr->color == BLACK)
		{
			b.addbp(nodeptr->place);
			sbnum++;
		}else
		{
			b.addwp(nodeptr->place);
			swnum++;
		}
		b.add(nodeptr->place,nodeptr->color);
	}

}

void MCTStree::update(double result,board& b)
{
	for(int i=0;i<path.size();i++)
	{
		// normal update
		path[i]->update_normal(result);

		// RAVE , look up the ctable , if not -1(undef) ,update
		// it seems that we can further simplified
		if(path[i] -> color == BLACK)
		{
			for(int j=0;j<b.wpsize;j++)
			{
				int k = (path[i]->ctable[b.wpath[j]]);
				if( k !=-1)	// if feasible , RAVE update
					((path[i]->childptr)+k)->update_rave(result);
			}
		}else
		{
			for(int j=0;j<b.bpsize;j++)
			{
				int k = (path[i]->ctable[b.bpath[j]]);
				if( k != -1)
					((path[i]->childptr)+k)->update_rave(result);
			}
		}
	}
}

// board utilities :
//	addbp : add a black move to its log
//	addbp : add a white move to its log
//	add : do a black/white move on board
//	getv : find the feasibility for each location, have "B","W","both" 3 type distoint
//		   correspond bone[BOARDSSIZE],wone[BOARDSSIZE],two[BOARDSSIZE] resp.
//	simulate : do a playout (should check how it work , omit first)
void MCTStree::run_a_cycle()
{
	board b;	//copy
	double result;
	b = rboard;
	sbnum=swnum=0;

	select(b);	// find path and leave node
	
	ucbnode &last=(*(path.back()));
	ucbnode *nodeptr = NULL;

	if(last.csize==0)	// by def we always select not yet expanded  node
	{
		last.expansion(b);
		if(last.csize!=0)	// still alive
		{
			// go on playing
			nodeptr = last.get_bestchild();
			path.push_back(nodeptr);
			
			// no change, board subrutine
			// we add the info. to board for RAVE lookup
			totalnode+=last.csize;
			if(nodeptr->color == 0)
			{
				b.addbp(nodeptr->place);
				sbnum++;
			}else
			{
				b.addwp(nodeptr->place);
				swnum++;
			}
			b.add(nodeptr->place,nodeptr->color);
			
		}
	}
	total += sbnum;
	total += swnum;

	// for this new state ,update the feasibility
	b.getv(bone,wone,two,bsize,wsize,tsize);
	
	if((b.just_play_color()==BLACK) && (wsize + tsize)==0)
	{
		// black did the prev. move, white loss
		result = 1;
	}else if(b.just_play_color()==WHITE && (bsize + tsize)==0)
	{
		// white wins
		result = -1;
	}else
	{
		// still live , board simulation
		// we regard as env. first. maybe need to modify in future
		result=b.simulate(!b.just_play_color(),bone,wone,two,bsize,wsize,tsize);
	}

	update(result,b);
}

void MCTStree::reset(board &b)
{
	rboard=b;
	root = new ucbnode;
	root->init_ucbnode(81,rboard.just_play_color());
	root-> expansion(b);
	
	// info.dummy
	total = 0;
	totalnode =0;
}


// utilities , no change
//----------------------------------------------
void MCTStree::show_path()
{
	ucbnode* nodeptr = root;
	int i,k;
	i=0;
	while( nodeptr->childptr != NULL && i<10)
	{
		k=nodeptr ->get_bestmove();
		nodeptr = nodeptr->childptr +k;
		i++;
		if(nodeptr != NULL){
			if(nodeptr->color == BLACK)
				cerr<<"B(";
			else
				cerr<<"W(";
			cerr<<inttostring(nodeptr -> place)<<") ";
		}
	}
	cerr<<endl;
}
void MCTStree::clear()
{
	if( root != NULL)delete root;
}
string MCTStree::inttoGTPstring(int i)
{
    string s = "A1";
    s[0]+= i / 9;
    if(s[0]>='I')s[0]++;
    s[1]+= i % 9;
    return s;
}
string MCTStree::inttostring(int i)
{
    return inttoGTPstring(i);
}

MCTStree::MCTStree()
{
	;
}

MCTStree::~MCTStree()
{
	;
}

