#include "Queue.h"
#include "Node.h"
#include "Stack.h"
#include "Exceptions.h"
#include "Card.h"

#include <iostream>
#include <string>
#include <random>

Stack<Card> Sidepile{};
Queue<Card> PlayerHand{};
Queue<Card> ComputerHand{};
Queue<Card> Drawpile{};
Stack<Card> WarStack{};

void war() { //just now realized the contest is supposed to be the sum of the cards. should be an easy fix but takes a tad bit of editing
	if (PlayerHand.length() < 3) {
		//while loop to pick up as many cards as needed
		//do a subtraction to figure out how many cards to pull from the side pile
		//if the side pile is empty, the player loses
		if (PlayerHand.length() == 2) {
			if (Sidepile.length() < 1) {
				//computer wins game
			}
			else {
				PlayerHand.enqueue(Sidepile.pop());
			}
		}
		else if (PlayerHand.length() == 1) {
			if (Sidepile.length() < 2) {
				//computer wins game
			}
			else {
				PlayerHand.enqueue(Sidepile.pop());
				PlayerHand.enqueue(Sidepile.pop());
			}
		}
		else if (PlayerHand.length() == 0) {
			if (Sidepile.length() < 3) {
				//computer wins game
			}
			else {
				PlayerHand.enqueue(Sidepile.pop());
				PlayerHand.enqueue(Sidepile.pop());
				PlayerHand.enqueue(Sidepile.pop());
			}
		}
	}	
	Card playerCard1 = PlayerHand.dequeue();
	Card playerCard2 = PlayerHand.dequeue();
	Card playerCard3 = PlayerHand.dequeue();
	Card computerCard1 = ComputerHand.dequeue();
	Card computerCard2 = ComputerHand.dequeue();
	Card computerCard3 = ComputerHand.dequeue();

	int ComputerCardSum = computerCard1.cardVal + computerCard2.cardVal + computerCard3.cardVal;
	int PlayerCardSum = playerCard1.cardVal + playerCard2.cardVal + playerCard3.cardVal;

	WarStack.push(playerCard1);
	WarStack.push(playerCard2);
	WarStack.push(playerCard3);
	WarStack.push(computerCard1);
	WarStack.push(computerCard2);
	WarStack.push(computerCard3);

	if (PlayerCardSum > ComputerCardSum) {
		//player wins war
		while (!(WarStack.length() == 0)) {
			PlayerHand.enqueue(WarStack.pop());
		}
	}
	else {
		//computer wins war
		while (!(WarStack.length() == 0)) {
			ComputerHand.enqueue(WarStack.pop());
		}
	}
}

void round(int& turns) {
	Card playerCard = PlayerHand.dequeue();
	Card computerCard = ComputerHand.dequeue();
	// show player their card and give them their options (stack or play)
	int playOption = 0;
	playerCard.display();
	std::cout << "1. Play\n2. Stack" << std::endl;
	std::cin >> playOption;

	while (!(playOption == 1 || playOption == 2)) {
		std::cout << "Please enter a valid option" << std::endl;
		std::cin >> playOption;
	}

	if (playOption == 2) {
		Sidepile.push(playerCard);
		playerCard = PlayerHand.dequeue(); //new card that must be played
	}

	if (playerCard.cardVal > computerCard.cardVal) {
		PlayerHand.enqueue(playerCard);
		PlayerHand.enqueue(computerCard);
	}
	else if (playerCard.cardVal < computerCard.cardVal) {
		ComputerHand.enqueue(playerCard);
		ComputerHand.enqueue(computerCard);
	}
	else { //if the cards are equal //this can be looped somehow
		WarStack.push(playerCard);
		WarStack.push(computerCard);
		war();
	}
	turns++;
}

void initCardPile(Queue<Card>& Drawpile) {
	std::string name;
	std::string suit;
	for (int v = 2; v < 15; v++) {
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
		for (int s = 0; s < 4; s++) {
			switch (s) {
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
			Card* tempCard = new Card(name, suit, v);
			//std::cout << tempCard->display() << std::endl;
			Drawpile.enqueue(*tempCard);
		}
	}
}

void shuffle(Queue<Card> &Drawpile,Queue<Card> &PlayerHand, Queue<Card> &ComputerHand) {
    //Currently not working will come back to work on this
    
    int pileSize = Drawpile.length();   //Get size of Draw pile

    //Create a random number between 0 and size of Drawpile
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, pileSize);
    
    Card tempArr[52];

    bool addPlayerHand = true;

    //Get an array of all the cards in the draw pile
    for (int i{}; i < pileSize; i++) {
        tempArr[i] = Drawpile.dequeue();
    }

    int randomValue = distrib(gen);
    for (int i{}; i < pileSize; i++) {
       
            if (tempArr[randomValue] != 0){
                if (addPlayerHand) {
                    PlayerHand.enqueue(tempArr[randomValue]);
                    tempArr[randomValue].cardVal = 0;
                    addPlayerHand = false;
                } else {
                    ComputerHand.enqueue(tempArr[randomValue]);
                    tempArr[randomValue].cardVal = 0; 
                    addPlayerHand = true;
                }
            }
            while (tempArr[randomValue] == 0) {
                randomValue = distrib(gen);
            }   
    }
}

int main() {

	// constructors (i see this is python syntax)
	//drawpile = Drawpile();
	//playerHand = PlayerHand();
	//computerHand = ComputerHand();
	//sidePile = Sidepile();

	initCardPile(Drawpile); //link just does to the function in this doc
	/*
    shuffle(Drawpile, PlayerHand, ComputerHand);//shuffle function

    std::cout << "Player Hand: " << std::endl;
    while(!PlayerHand.isEmpty()) {
        std::cout << PlayerHand.dequeue().display() << std::endl;
    }

    std::cout << "Computer Hand: " << std::endl;
    while(!PlayerHand.isEmpty()) {
        std::cout << ComputerHand.dequeue().display() << std::endl;
    }
    */
	bool handIsEmpty = false;
	int turns = 0;

	while (handIsEmpty) {
		round(turns);
		if (PlayerHand.isEmpty() || ComputerHand.isEmpty()) {
			handIsEmpty = true;
			break;
		}
	}


	return 0;
}
