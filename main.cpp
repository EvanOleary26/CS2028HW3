#include <iostream>

#include "Queue.h"
#include "Stack.h"
/*
Function: 
	initCardPile - 
Input:
	Queue<Node<Card>> drawPile - The current pile for both players
Goal: 
	Initialize a full deck of cards giving each card its name, suit, and card value
Returns:
	nothing, void
*/
void initCardPile(Queue<Card> &drawPile) { 
    std::string name;
    std::string suit;
    for (int v=2; v<15; v++){
        switch (v) {
            case 2: { 
                name = "Two"; 
                break;
            } 
            case 3: { 
                name = "Three";
                break;
            }
            case 4: { 
                name = "Four"; 
                break;
            }
            case 5: { 
                name = "Five"; 
                break;
            }
            case 6: { 
                name = "Six"; 
                break;
            }
            case 7: { 
                name = "Seven"; 
                break;
            }
            case 8: { 
                name = "Eight"; 
                break;
            }
            case 9: { 
                name = "Nine"; 
                break;
            }
            case 10: { 
                name = "Ten"; 
                break;
            }	
            case 11: { 
                name = "Jack"; 
                break;
            }
            case 12: { 
                name = "Queen"; 
                break;
            }
            case 13: {
                name = "King"; 
                break;
            }
            case 14: {
                name = "Ace"; 
                break;
            }
        }
        for (int s = 0; s<4; s++){
            switch(s) {
                case 0: { 
                    suit = "Spades"; 
                    break;
                }
                case 1: { 
                    suit = "Hearts"; 
                    break;
                }
                case 2: { 
                    suit = "Clubs";
                    break;
                }
                case 3: { 
                    suit = "Diamonds"; 
                    break;
                }
            }
            Card *tempCard = new Card(name, suit, v);
            //std::cout << tempCard->display() << std::endl;
            drawPile.enqueue(*tempCard); 
        }
    }
}

/*
Function: 
	war - 
Input:

Goal: 

Returns:
*/

/*
void war(){
	if (playerHand.size >= 3 && computerHand.size >=3)
        playerWarCard1 = playerHand.dequeue();
        playerWarCard2 = playerHand.dequeue();
        playerWarCard3 = playerHand.dequeue();
        computerWarCard1 = computerHand.dequeue();
        computerWarCard2 = computerHand.dequeue();
        computerWarCard3 = computerHand.dequeue();
    if (playerWarCard3 ->data.cardVal > computerWarCard3 ->data.cardVal){
        playerHand.enqueue(playerCard);
        playerHand.enqueue(computerCard);
    } else if (playerWarCard3->data.cardVal < computerWarCard3 ->data.cardVal){
        computerHand.enqueue(playerCard);
        computerHand.enqueue(computerCard);
    } else {
        //we need a war stack to handle all these extra cards before recursion
        warStack.push(playerWarCard1);
        warStack.push(playerWarCard2);
        warStack.push(playerWarCard3);
        warStack.push(computerWarCard1);
        warStack.push(computerWarCard2);
        warStack.push(computerWarCard3);
	war();
    }

    } //double war
    } else {} //if there are not enough cards to do a war (i forget the rule) – rule is just the last card
    //”If a participant runs out of cards in their deck, they must play cards from their side pile. If a participant runs out of cards in there deck and side pile, they lose.” – assignment
}
}
*/

/*
Function: 
	round - 
Input:

Goal: 

Returns:
*/

/*
void round(){
	playerCard = playerHand.dequeue();
	computerCard = computerHand.dequeue();
	// show player their card and give them their options (stack or play)
	if (playerCard->data.cardVal > computerCard->data.cardVal){
		playerHand.enqueue(playerCard);
		playerHand.enqueue(computerCard);
    } else if (playerCard->data.cardVal < computerCard->data.cardVal){
            computerHand.enqueue(playerCard);
            computerHand.enqueue(computerCard);
    } else { //if the cards are equal //this can be looped somehow
            war();
    }
    turns++;
}

*/

/*
Function: 
	shuffleDeck - 
Input:

Goal: 

Returns:
*/
void shuffleDeck() {

}
    
int main() {
    Stack<Card> Sidepile;
    Queue<Card> PlayerHand;
    Queue<Card> ComputerHand;
    Queue<Card> Drawpile;
    Stack<Card> WarStack;

    //temporary testing
    try{ 
        initCardPile(Drawpile);

        std::cout << "Drawpile size = " << Drawpile.length() << std::endl;

        while (!Drawpile.isEmpty()){
            std::cout << Drawpile.dequeue().display() << std::endl;
        }
    }
    catch(Exception &e) {
        std::cout << e.errorMessage << ": " << e.errorNumber << std::endl;
    }







    return 0;
}