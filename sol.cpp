#include <utility>
#include <vector>
#include <map>
#include "sol.h"

using namespace std;

//return -1,-1 for no valid rook placements
pair<int,int> Solution::findNextRook(vector<pair<int,int>>& rooks){
	//so basically, as long as I find a space that doesn't collide with the current rooks,
	//it will be a valid position, since we are using rooks and not queens.

	//2 vectors, 0-7, 1 for x, 1 for y
	//actually maybe use hash table for the x, y, and to determine x,y position, check 
	//if position is in the table

	//basic edge case
	if(rooks.size() > 7){
		return pair<int,int>(-1,-1);
	}

	map<int,int> mx, my;
	
	for(int i = 0; i < rooks.size(); i++){
		mx[rooks[i].first] = 1;
		my[rooks[i].second] = 1;
	}
	int x = -1, y = -1;
	//get first valid x
	for(int i = 0; i < 7; i++){
		if(mx.find(i) == mx.end()){
			x = i;
			break;
		}
	}
	//get first valid y
	for(int i = 0; i < 7; i++){
		if(my.find(i) == my.end()){
			y = i;
			break;
		}
	}
	return pair<int,int>(x,y);
}
