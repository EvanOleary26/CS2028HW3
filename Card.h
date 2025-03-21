#ifndef __CARD__H
#define __CARD__H

#include <iostream>

class Card {
    public:
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

        std::string display() const {
            return cardType + " of " + suit;
        }

        // Overload the << operator for Card
        friend std::ostream& operator<<(std::ostream& os, const Card& card) {
            card.display(); // Call display() to output card details
            return os;
        }
};









#endif
