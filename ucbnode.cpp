#include "ucbnode.h"

//-----------------------------------
ucbnode::ucbnode(){}
ucbnode::~ucbnode()
{
    if(childptr != NULL) {
		delete [] childptr;
		childptr=NULL;
	}
}
//-----------------------------------

void ucbnode::init_ucbnode(int move_loc,bool who)
{
    color = who;
    place = move_loc;
    normal_mean = rave_mean = MEAN_INIT;
	normal_count = NORMAL_COUNT_INIT;
    rave_count = RAVE_COUNT_INIT;
	csize=0;
    childptr=NULL;
	memset(ctable,-1,sizeof(ctable));
}

// since we have init. by heuristic , the formula seems to not work
void ucbnode::update_normal(double result)
{
	// using the magic formula
	// ++normal_count;
	// normal_mean += (result-normal_mean)/normal_count;

    if((result > 0 && color==BLACK) || (result < 0 && color==WHITE) ){
        normal_mean = (normal_mean * normal_count + 1.00) / (normal_count + 1);
    }else{
        normal_mean = (normal_mean * normal_count) / (normal_count + 1);
    }
    ++normal_count;
}
void ucbnode::update_rave(double result)
{
	// using the magic formula
	// ++rave_count;
	// rave_mean += (result-rave_mean)/rave_count;

    if((result > 0 && color==BLACK) || (result < 0 && color==WHITE) )
    {
        rave_mean = (rave_mean*rave_count+1.00)/(rave_count+1);
    }else
    {
        rave_mean = (rave_mean*rave_count)/(rave_count+1);
    }
    ++rave_count;
}

//	board utilities :
//	just_play_color : get the last move player
void ucbnode::expansion(board &b)
{
	bool next_player = !b.just_play_color();
	
	// find feasible as children
	csize=0;
	for(int loc=0; loc<BOARDSSIZE; loc++)
		if(b.check(loc,next_player)) csize++;

	if(csize==0)
		return;		// no move

	childptr = new ucbnode [csize];

	for(int loc=0,k=0; loc<BOARDSSIZE ;loc++)
	{
		if(b.check(loc,next_player)){
			ctable[loc] = k;
			childptr[k++].init_ucbnode(loc,next_player);
		}
	}
}

// simply to choose most frequently visited node ,randomly if multiple
// note that this usually for final decision
// for RAVE ,we use get_bestchild ,which consider the exploration bonus
int ucbnode::get_bestmove()
{
	int idx = -1;
	double max_cnt = -100;
	for(int i = 0; i<csize; i++)
	{
		if(childptr[i].normal_count > max_cnt)
		{
			max_cnt = childptr[i].normal_count;
			idx = i;
		}
	}
	return idx;
}

// return the dist. for next move 
vector<float> ucbnode::get_policy()
{
	vector<float> ret(BOARDSSIZE, 0);
	float sum = 0;
	for (int i = 0; i < csize; i++)
	{
		sum+= childptr[i].normal_count;
	}
	for (int i = 0; i < csize; i++)
	{
		ret[childptr[i].place] = childptr[i].normal_count / sum;
	}
	return ret;
}

// implement some functions in MCTS
double ucbnode::get_score(int child_idx)
{
	if (this->childptr == NULL) return 0;
	ucbnode &child = (this->childptr)[child_idx];
	// // test b = 0.025 as lecture suggests
	// double RAVE_BETA = child.rave_count/(child.normal_count+child.rave_count 
	// 										+ 0.0025*child.normal_count*child.rave_count); 
	// double AMAF_score = (1-RAVE_BETA)*child.normal_mean + (RAVE_BETA)*child.rave_mean;
	// double RAVE_score = AMAF_score + UCB_WEIGHT * sqrt(log(this->normal_count)/child.normal_count);

	// return RAVE_score;
	// here we ignore 4*n*n_rave*b^2 term in beta , care of round-off
	double count_sum = (child.normal_count + child.rave_count);
	// double RAVE_BETA = child.rave_count/(child.normal_count+child.rave_count); 
	double AMAF_score = child.normal_count*child.normal_mean + child.rave_count*child.rave_mean; // not yet divided by n+rn 
	double RAVE_score = AMAF_score 
					+ UCB_WEIGHT * sqrt(log(this->normal_count)*child.normal_count);	// why......

	return RAVE_score/count_sum;
}

ucbnode* ucbnode::get_bestchild()
{
	if(childptr == NULL) return NULL;
	int idx=0 ,k;
	int seed = rand() % csize;	// give the randomness when the same
	double score_hold = -99999999, score_tmp = 0;
	
	for(int i=0;i<csize;i++)
	{
		k = (seed+i)%csize;
		score_tmp = get_score(k);
		if ((score_tmp-score_hold) > 1e-5)	// see as greater
		{
			score_hold = score_tmp;
			idx = k;
		}
	}

	return (childptr+idx);
}

// -----------------------------------------------------------------------------
//	printing utilities
//------------------------------------------------------------------------------
void ucbnode::show_child()
{
	for(int i=0;i<csize;i++)
	{
		if(childptr[i].normal_count<10)continue;
		cerr<< inttoGTPstring((int)childptr[i].place)<<' '<<childptr[i].normal_mean<<' '<<childptr[i].normal_count<<' ';
		cerr<<(childptr[i].rave_mean)<<' '<<(childptr[i].rave_count)<<endl;
	}
}
float ucbnode::show_inf(int best)
{
		cerr<<"total : "<< normal_count - NORMAL_COUNT_INIT <<endl<<"winrate :"<<(childptr[best].normal_mean);
		cerr<<"\nrave : "<<(childptr[best].rave_mean)<<' '<<(childptr[best].rave_count)<<endl;
		return childptr[best].normal_mean;
}

string ucbnode::inttoGTPstring(int i)
{
    string s = "A1";
    s[0]+= i / 9;
    if(s[0]>='I')s[0]++;
    s[1]+= i % 9;
    return s;
}
string ucbnode::inttostring(int i)
{
    return inttoGTPstring(i);
}