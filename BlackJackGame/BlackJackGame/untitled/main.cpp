//
//  main.cpp
//  untitled
//
//  Created by Yacer Razouani on 2018-04-21.
//  Copyright © 2018 Yacer Razouani. All rights reserved.
//

#include <iostream>
#include "Cards.hpp"

using namespace std;

int main()
{
    
    srand (time(NULL));
    cout << "============================= \n";
    cout << "==== BIENVENUE BLACKJACK ==== \n";
    cout << "============================= \n";
    cout << "Enter your name: \n";
    string userName;
    cin >> userName;
    
    Cards cards;
    cards.distribute(userName);
    
    cards.verifyHouseScore();
    cards.verifyPlayerScore();
    char userResponse;
    do {
        cout << "Hit or Stay? (h/s) \n";
        cin >> userResponse;
        if(userResponse == 'h')
        {
            cards.hitUser();

            if (cards.getPlayerScore() >= 21)
            {
                cards.showHouse();
                cards.showHouseScore();
                cards.showPlayerScore();
                
                if(cards.getHouseScore() > cards.getPlayerScore() || cards.getHouseScore() <= 21)
                    cout << "THE HOUSE WINS\n";
                if(cards.getPlayerScore() > cards.getHouseScore() || cards.getPlayerScore() <= 21)
                    cout << "PLAYER WINS\n";
                if(cards.getHouseScore() == cards.getPlayerScore() || cards.getPlayerScore() <= 21)
                    cout << "PUSH\n";
                return 0;
            }
        }
        else
        {
            cards.showHouse();
            cards.showHouseScore();
            cards.showPlayerScore();
            if(cards.getHouseScore() > cards.getPlayerScore())
                cout << "THE HOUSE WINS\n";
            if(cards.getPlayerScore() > cards.getHouseScore())
                cout << "PLAYER WINS\n";
            if(cards.getHouseScore() == cards.getPlayerScore())
                cout << "PUSH\n";
        }
    }while (userResponse == 'h');
    
}
