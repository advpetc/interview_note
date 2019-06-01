//
//  main.cpp
//  LeetcodeTest
//
//  Created by ChenHaoyang on 5/25/19.
//  Copyright © 2019 ChenHaoyang. All rights reserved.
//

#include <iostream>
#include "WordSearchII.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    WordSearchII ws2;
    vector<vector<char>> board {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    vector<string> words{"oath","pea","eat","rain"};
    vector<string> ret = ws2.findWords(board, words);
    for(string r : ret)
        cout << r << endl;
    return 0;
}
