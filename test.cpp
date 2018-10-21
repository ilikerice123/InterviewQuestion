#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <utility>
#include <vector>
#include "sol.h"

using namespace std;

//returns true if rook placement does not collide with current rooks
bool checkRook(pair<int,int> rook, vector<pair<int,int>> rookList){
	for(int i = 0; i < rookList.size(); i++){
		if(rook.first == rookList[i].first || 
			rook.second == rookList[i].second) return false;
	}
	return true;
}

TEST_CASE("Checking my check rook function LOL"){
	vector<pair<int,int>> v;
	
	//empty
	pair<int,int> p(1,1);
	REQUIRE(checkRook(p, v) == true);

	v.push_back(p);
	REQUIRE(checkRook(p, v) == false);

	pair<int,int> q(2,2);
	REQUIRE(checkRook(q, v) == true);

	v.push_back(pair<int,int>(2,2));
	v.push_back(pair<int,int>(3,0));

	pair<int,int> r(0,0);
	REQUIRE(checkRook(r, v) == false);
	pair<int,int> s(3,7);
	REQUIRE(checkRook(s, v) == false);
	pair<int,int> t(6,7);
	REQUIRE(checkRook(t, v) == true);
}
