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

TEST_CASE( "Empty Board"){
		vector<pair<int,int>> v;
}

TEST_CASE( "Malformed Input 1- full board"){

}

TEST_CASE( "Malformed Input 2 - initial rooks colliding"){

}

TEST_CASE( "Malformed Input 3 - multiple rooks on same square"){

}

TEST_CASE( "Misc. Rooks 1 - just one rook"){

}

TEST_CASE( "Misc. Rooks 2 - rooks close together"){

}

TEST_CASE( "Misc. Rooks 3 - rooks close to x = 0"){

}

TEST_CASE( "Misc. Rooks 4 - rooks close to y = 0"){

}

TEST_CASE( "Misc. Rooks 5 - rooks anywhere"){

}

TEST_CASE( "Misc. Rooks 6 - only 1 possible square"){

}

TEST_CASE( "Misc. Rooks 7 - only 1 possible square v2"){

}

TEST_CASE( "Fill board 1 - from empty"){

}

TEST_CASE( "Fill board 2 - from half-populated"){

}

TEST_CASE( "Fill board 3 - 2 placements"){

}
