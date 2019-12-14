#ifndef UCBNODE_H
#define UCBNODE_H
#include "board.h"
#include <math.h>

// UCB exploration constant
const double UCB_WEIGHT = 0.25;

// heuristic const 
#define MEAN_INIT 0.5	
#define NORMAL_COUNT_INIT 0
#define RAVE_COUNT_INIT 20

class ucbnode
{

public:
	char place; // move location
	bool color;	// who did this move
	
	// children info.
	int csize;	
	ucbnode *childptr;
	char ctable[BOARDSSIZE+1];	// child lookup table for RAVE
	
	// counting info.
	double normal_count;		
	double normal_mean;  		
	double rave_count;	
	double rave_mean;	

	// self try
    void init_ucbnode(int move_loc,bool who);
    void update_normal(double result);
    void update_rave(double result);
    int get_bestmove();
	vector<float> get_policy();
	void expansion(board &b);

	// some func. in MCTStree.h move to here
	double get_score(int child_idx);
	ucbnode* get_bestchild();
    
	// no change
	void show_child();
    float show_inf(int child);
	string inttostring(int i);
    string inttoGTPstring(int i);
	ucbnode();
	~ucbnode();
};
#endif //UCBNODE_H

/*
-----------------------------------------
some note for ucb node
-----------------------------------------
1. 	we have to maintain "normal winrate" and "RAVE(AMAF) winrate" resp.
   	in RAVE ,we have to use the weighted of the two

	the update policy of the two differ ,but in here we simply 
	do the update for a playout, leaving it in MCTS implemtation

2. 	UCB expansion : local node expansion ,to expand ,we would first check
	all feasible next move ,recording as "children" node, actually it suffice 
	to maintain the children list itself. And locally maintain the children UCB list
	the init for children : heuristic

3. 	getBestMove : choose the child having most count

4. 	getPolicy : return the dist. for children

5. 	we leave some printing and protocol utilities 
*/