#ifndef MCTS_H
#define MCTS_H
#include "ucbnode.h"
#define raveb 0.0001
class MCTStree
{
public:

	ucbnode* root;
	board rboard;

    MCTStree();
    ~MCTStree();

    vector<ucbnode*> path;

    // simulation related
	int bsize,wsize,tsize;
	int bone[BOARDSSIZE],wone[BOARDSSIZE],two[BOARDSSIZE];

    // info. dummy
	int sbnum,swnum;//select num
	int total;
	int totalnode;

    // self try
    void select(board &b);
    void update(double result,board& b);
    void run_a_cycle();
    void reset(board &b);

    // no change
    void clear();
	void show_path();
    string inttostring(int i);
    string inttoGTPstring(int i);
};


#endif // MCTS_H

/*
-----------------------------------------
some note for MCTS : 4 step
-----------------------------------------
1. 	select : select a path and node to expand
    the selecting policy is done in ucb node

2. 	UCB expansion : alreaady done in ucb node

3. 	play out : here we have "run_a_cycle" function to play a move ,
    the simulation depth is controlled in Main 

4. 	update : backprop. the playout result, note that here we adapt
    RAVE, hence we have to deal with the side-update by RAVE 
    this function would be called in the playout

*/