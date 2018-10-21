#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include <vector>
#include "sol.h"

using namespace std;

int main(int argc, char* argv[]){
	if(argc != 2){
		cout << "usage: " << argv[0] << " <filename>" << endl;
		return 0;
	}

	ifstream reader(argv[1]);
	ofstream writer("output.txt");

	if(reader.is_open() && writer.is_open()){
		try{
			//parsing the actual text
			string s;
			getline(reader, s);
			int numCases = stoi(s);
			for(int i = 0; i < numCases; i++){
				if(!getline(reader, s)) throw invalid_argument("eof reached");
				if(s.empty()){
					i--;
					continue;
				}
				
				int x,y;
				vector<pair<int,int>> rooks;
				for(int j = 0; j < s.length(); j++){
					if(s[j] >= 'a' && s[j] < 'i'){
						x = s[j] - 'a';
						//read the next character, hoping that it's a number
						y = s[++j] - '1';
						if(y > 7 || y < 0) throw invalid_argument("invalid rook coordinates");
						
						rooks.push_back(pair<int,int>(x,y));
					}
				}

				pair<int,int> nextRook = Solution().findNextRook(rooks);
				char first = 'a' + nextRook.first;
				char second = '1' + nextRook.second;
				writer << first << second << endl;
			}
		}
		catch(const invalid_argument& a){
			cout << "Error reading through file contents. Program terminated" << endl;
		}
	}
	else {
		cout << "Error with file I/O. Program terminated" << endl;
	}
	
	return 0;
}
