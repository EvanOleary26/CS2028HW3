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

int main() {

	// constructors (i see this is python syntax)
	//drawpile = Drawpile();
	//playerHand = PlayerHand();
	//computerHand = ComputerHand();
	//sidePile = Sidepile();

	initCardPile(Drawpile); //link just does to the function in this doc
	//shuffle function

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
