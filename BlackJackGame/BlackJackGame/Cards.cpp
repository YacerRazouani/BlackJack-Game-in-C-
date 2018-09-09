//
//  Cards.cpp
//  untitled
//
//  Created by Yacer Razouani on 2018-04-21.
//  Copyright © 2018 Yacer Razouani. All rights reserved.
//

#include "Cards.hpp"
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

Cards::Cards()
{
    //DIAMONDS
    card_.push_back("ACE of diamonds");
    card_.push_back("2 of diamonds");
    card_.push_back("3 of diamonds");
    card_.push_back("4 of diamonds");
    card_.push_back("5 of diamonds");
    card_.push_back("6 of diamonds");
    card_.push_back("7 of diamonds");
    card_.push_back("8 of diamonds");
    card_.push_back("9 of diamonds");
    card_.push_back("J of diamonds");
    card_.push_back("Q of diamonds");
    card_.push_back("K of diamonds");
    //HEARTS
    card_.push_back("ACE of hearts");
    card_.push_back("2 of hearts");
    card_.push_back("3 of hearts");
    card_.push_back("4 of hearts");
    card_.push_back("5 of hearts");
    card_.push_back("6 of hearts");
    card_.push_back("7 of hearts");
    card_.push_back("8 of hearts");
    card_.push_back("9 of hearts");
    card_.push_back("J of hearts");
    card_.push_back("Q of hearts");
    card_.push_back("K of hearts");
    //SPADES
    card_.push_back("ACE of spades");
    card_.push_back("2 of spades");
    card_.push_back("3 of spades");
    card_.push_back("4 of spades");
    card_.push_back("5 of spades");
    card_.push_back("6 of spades");
    card_.push_back("7 of spades");
    card_.push_back("8 of spades");
    card_.push_back("9 of spades");
    card_.push_back("J of spades");
    card_.push_back("Q of spades");
    card_.push_back("K of spades");
    //CLUBS
    card_.push_back("ACE of clubs");
    card_.push_back("2 of clubs");
    card_.push_back("3 of clubs");
    card_.push_back("4 of clubs");
    card_.push_back("5 of clubs");
    card_.push_back("6 of clubs");
    card_.push_back("7 of clubs");
    card_.push_back("8 of clubs");
    card_.push_back("9 of clubs");
    card_.push_back("J of clubs");
    card_.push_back("Q of clubs");
    card_.push_back("K of clubs");
    
    playerScore_ = 0;
    houseScore_ = 0;
}

void Cards::distribute(string& name)
{
    //srand (time(NULL));
    int temp = rand() % card_.size();               //generate random number between 0 and 52.
    
    for (int i = 0; i < 2; i++)                     //distributes 2 cards to the HOUSE.
    {
        //cout << card_[temp] << endl;
        house_.push_back(card_[temp]);              //adds card to the HOUSE'S hand
        card_.erase(card_.begin() + temp);          //deletes distributed card from the pack
        temp = rand() % card_.size();
    }
    
    cout << "--" << name << "--" << endl;
    for (int i = 0; i < 2; i++)                     //distributes 2 cards to the PLAYER.
    {
        cout << card_[temp] << endl;
        player_.push_back(card_[temp]);             //adds card to the PLAYER'S hand
        card_.erase(card_.begin() + temp);          //deletes distributed card from the pack
        temp = rand() % card_.size();
    }
}

void Cards::showHouse()
{
    cout << "--THE HOUSE--" << endl;
    for(int i = 0; i < 2; i++)
        cout << house_[i] << endl;
}

int compteur = 2;
void Cards::hitUser()
{
    int temp = rand() % card_.size();               //generate random number between 0 and 52.
    
    for (int i = 0; i < 1; i++)                     //distributes 2 cards to the PLAYER.
    {
        cout << card_[temp] << endl;
        player_.push_back(card_[temp]);
        card_.erase(card_.begin() + temp);          //deletes distributed card from the pack
    }
    
    if (player_[compteur][0] == 'K' || player_[compteur][0] == 'Q' || player_[compteur][0] == 'J')
        playerScore_ += 10;
    else if (player_[compteur][0] == 'A')
    {
        playerScore_ += 11;
        if (playerScore_ > 21)
            playerScore_ -= 10;            //ACE equals either 1 or 11.
    }
    else
        playerScore_ += player_[compteur][0] - '0';
    compteur++;
}

void Cards::verifyHouseScore()
{
    for(int i = 0; i < house_.size(); i++)
    {
        if (house_[i][0] == 'K' || house_[i][0] == 'Q' || house_[i][0] == 'J')
            houseScore_ += 10;
        else if (house_[i][0] == 'A')
        {
            houseScore_ += 11;
            if (houseScore_ > 21)
                houseScore_ -= 10;            //ACE equals either 1 or 11.
        }
        else
            houseScore_ += house_[i][0] - '0';
    }
    if(houseScore_ > 21)
        cout << "HOUSE is busted\n";
    if(houseScore_ == 21)
        cout << "HOUSE has Blackjack!\n";
}

void Cards::verifyPlayerScore()
{
    for(int i = 0; i < player_.size(); i++)
    {
        if (player_[i][0] == 'K' || player_[i][0] == 'Q' || player_[i][0] == 'J')
            playerScore_ += 10;
        else if (player_[i][0] == 'A')
        {
            playerScore_ += 11;
            if (playerScore_ > 21)
                playerScore_ -= 10;            //ACE equals either 1 or 11.
        }
        else
            playerScore_ += player_[i][0] - '0';
    }
    if(playerScore_ > 21)
        cout << "PLAYER is busted\n";
    if(playerScore_ == 21)
        cout << "PLAYER has Blackjack!\n";
}

void Cards::showHouseScore()
{
    cout << "---HOUSE'S Score---\n" << houseScore_ << endl;
}

void Cards::showPlayerScore()
{
    cout << "---PLAYER'S Score---\n" << playerScore_ << endl;
}

int Cards::getHouseScore()
{
    return houseScore_;
}
int Cards::getPlayerScore()
{
    return playerScore_;
}
