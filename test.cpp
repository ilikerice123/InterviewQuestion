#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <utility>
#include <vector>
#include "sol.h"

using namespace std;

//returns true if rook placement does not collide with current rooks
bool checkRook(pair<int,int> rook, vector<pair<int,int>> rookList){
	if(rook.first == -1 && rook.second == -1) return false;
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

TEST_CASE( "Empty Board"){
	vector<pair<int,int>> v;
	pair<int,int> p = Solution().findNextRook(v);
	
	REQUIRE(v.empty());
	REQUIRE(checkRook(p, v));
}

TEST_CASE( "Malformed Input 1- full board"){
	vector<pair<int,int>> v;
	pair<int,int> error(-1,-1);

	for(int i = 0; i < 8; i++){
		v.push_back(pair<int,int>(i,i));
	}
	pair<int,int> p = Solution().findNextRook(v);
	
	REQUIRE(p == error);
}

TEST_CASE( "Malformed Input 2 - initial rooks colliding"){
	vector<pair<int,int>> v;
	v.push_back(pair<int,int>(2,1));
	v.push_back(pair<int,int>(4,1));
	v.push_back(pair<int,int>(3,2));
	v.push_back(pair<int,int>(4,2));

	pair<int,int> p = Solution().findNextRook(v);
	REQUIRE(checkRook(p, v));
}

TEST_CASE( "Malformed Input 3 - multiple rooks on same square"){
	vector<pair<int,int>> v;
	v.push_back(pair<int,int>(5,5));
	v.push_back(pair<int,int>(5,5));
	v.push_back(pair<int,int>(1,1));
	v.push_back(pair<int,int>(1,1));

	pair<int,int> p = Solution().findNextRook(v);
	REQUIRE(checkRook(p, v));
}

TEST_CASE( "Misc. Rooks 1 - just one rook"){
	vector<pair<int,int>> v;
	v.push_back(pair<int,int>(2,1));

	pair<int,int> p = Solution().findNextRook(v);
	REQUIRE(checkRook(p, v));
}

TEST_CASE( "Misc. Rooks 2 - just one rook v2"){
	vector<pair<int,int>> v;
	v.push_back(pair<int,int>(0,0));

	pair<int,int> p = Solution().findNextRook(v);
	REQUIRE(checkRook(p, v));
}

TEST_CASE( "Misc. Rooks 3 - rooks close to x axis"){
	vector<pair<int,int>> v;
	v.push_back(pair<int,int>(7,0));
	v.push_back(pair<int,int>(1,1));
	v.push_back(pair<int,int>(5,3));

	pair<int,int> p = Solution().findNextRook(v);
	REQUIRE(checkRook(p, v));
}

TEST_CASE( "Misc. Rooks 4 - rooks close to y axis"){
	vector<pair<int,int>> v;
	v.push_back(pair<int,int>(0,0));
	v.push_back(pair<int,int>(3,6));

	pair<int,int> p = Solution().findNextRook(v);
	REQUIRE(checkRook(p, v));
}

TEST_CASE( "Misc. Rooks 5 - blocking first guesses"){
	vector<pair<int,int>> v;
	v.push_back(pair<int,int>(4, 0));
	v.push_back(pair<int,int>(1, 1));
	v.push_back(pair<int,int>(2, 7));

	pair<int,int> p = Solution().findNextRook(v);
	REQUIRE(checkRook(p, v));
}

TEST_CASE( "Misc. Rooks 6 - rooks near center of board"){
	vector<pair<int,int>> v;
	v.push_back(pair<int,int>(4,4));
	v.push_back(pair<int,int>(3,3));
	v.push_back(pair<int,int>(5,2));

	pair<int,int> p = Solution().findNextRook(v);
	REQUIRE(checkRook(p, v));
}

TEST_CASE( "Misc. Rooks 7 - only 1 possible square"){
	vector<pair<int,int>> v;
	for(int i = 0; i < 7; i++){
		v.push_back(pair<int,int>(i,i));
	}

	pair<int,int> p = Solution().findNextRook(v);
	REQUIRE(checkRook(p, v));
}

TEST_CASE( "Misc. Rooks 8 - only 1 possible square v2"){
	vector<pair<int,int>> v;
	v.push_back(pair<int,int>(0,7));
	v.push_back(pair<int,int>(1,4));
	v.push_back(pair<int,int>(2,6));
	v.push_back(pair<int,int>(4,2));
	v.push_back(pair<int,int>(5,5));
	v.push_back(pair<int,int>(6,3));
	v.push_back(pair<int,int>(7,1));

	pair<int,int> p = Solution().findNextRook(v);
	REQUIRE(checkRook(p, v));
}

TEST_CASE( "Fill board 1 - from empty"){
	vector<pair<int,int>> v;
	pair<int,int> error(-1,-1);
	
	//should be able to place 8 rooks
	for(int i = 0; i < 8; i++){
		pair<int,int> p = Solution().findNextRook(v);
		REQUIRE(checkRook(p, v));
		v.push_back(p);
	}
	pair<int,int> p = Solution().findNextRook(v);
	REQUIRE(p == error);
}

TEST_CASE( "Fill board 2 - from half-populated"){
	vector<pair<int,int>> v;
	pair<int,int> error(-1,-1);
	v.push_back(pair<int,int>(1, 2));
	v.push_back(pair<int,int>(3, 4));
	v.push_back(pair<int,int>(5, 6));
	v.push_back(pair<int,int>(6, 5));
	for(int i = 0; i < 4; i++){
		pair<int,int> p = Solution().findNextRook(v);
		REQUIRE(checkRook(p, v));
		v.push_back(p);
	}
	pair<int,int> p = Solution().findNextRook(v);
	REQUIRE(p == error);
}

TEST_CASE( "Fill board 3 - 2 placements"){
	vector<pair<int,int>> v;
	pair<int,int> error(-1,-1);
	v.push_back(pair<int,int>(0,0));
	v.push_back(pair<int,int>(1,6));
	for(int i = 0; i < 6; i++){
		pair<int,int> p = Solution().findNextRook(v);
		REQUIRE(checkRook(p, v));
		v.push_back(p);
	}
	pair<int,int> p = Solution().findNextRook(v);
	REQUIRE(p == error);
}
