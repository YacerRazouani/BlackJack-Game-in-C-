//
//  Cards.hpp
//  untitled
//
//  Created by Yacer Razouani on 2018-04-21.
//  Copyright © 2018 Yacer Razouani. All rights reserved.
//

#ifndef Cards_hpp
#define Cards_hpp

#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Cards
{
public:
    Cards();
    void distribute(string& name);
    void showHouse();
    //void showUser();
    //void hitHouse();
    void hitUser();
    void verifyHouseScore();
    void verifyPlayerScore();
    void showHouseScore();
    void showPlayerScore();
    int getHouseScore();
    int getPlayerScore();
private:
    vector<string> card_;
    vector<string> house_;
    vector<string> player_;
    int playerScore_;
    int houseScore_;
};

#endif /* Cards_hpp */
