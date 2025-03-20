#ifndef __CARD__H
#define __CARD__H

#include <string>

class Card {
    private:
        std::string cardType;
        std::string suit;
        int cardVal = 0;

    
        //Constructors
        Card() : cardType(""), suit(""), cardVal(0) {};
        Card(std::string inType, std::string inSuit, int inCardVal) : cardType(inType), suit(inSuit), cardVal(inCardVal) {}; 
        
        //Functions
        std::string getCardType() { return cardType; }
        std::string getSuit() { return suit; }
        int getCardVal() { return cardVal; }
};









#endif