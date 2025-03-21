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

void round(int &turns) {
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

void war() { //just now realized the contest is supposed to be the sum of the cards. should be an easy fix but takes a tad bit of editing
	if (PlayerHand.length() >= 3) {
		WarStack.push(PlayerHand.dequeue()); //playerWarCard1
		WarStack.push(PlayerHand.dequeue()); //playerWarCard2
		WarStack.push(ComputerHand.dequeue()); //computerWarCard1
		WarStack.push(ComputerHand.dequeue()); //computerWarCard2

		Card playerContestCard = PlayerHand.dequeue();  //playerWarCard3
		Card computerContestCard = ComputerHand.dequeue(); //computerWarCard3

		if (playerContestCard.cardVal > computerContestCard.cardVal) {
			//player wins war
			PlayerHand.enqueue(playerContestCard);
			PlayerHand.enqueue(computerContestCard);
			while (!(WarStack.length() == 0)) {
				PlayerHand.enqueue(WarStack.pop());
			}
		}
		else if (playerContestCard.cardVal < computerContestCard.cardVal) {
			//computer wins war
			ComputerHand.enqueue(playerContestCard);
			ComputerHand.enqueue(computerContestCard);
			while (!(WarStack.length() == 0)) {
				ComputerHand.enqueue(WarStack.pop());
			}
		}
		else {
			//we need a war stack to handle all these extra cards before recursion
			WarStack.push(playerContestCard);
			WarStack.push(computerContestCard);
			war();
		} //double war
	} else { //loop to pull from the stack
		//while loop to pick up as many cards as possible
		//do a subtraction to figure out how many cards to pull from the side pile
		//if the side pile is empty, the player loses
		if (PlayerHand.length() == 2) {
			if (Sidepile.length() < 1) {
				//computer wins
			}
			else {
				PlayerHand.enqueue(Sidepile.pop());
			}
		}
		else if (PlayerHand.length() == 1) {
			if (Sidepile.length() < 2) {
				//computer wins
			}
			else {
				PlayerHand.enqueue(Sidepile.pop());
				PlayerHand.enqueue(Sidepile.pop());
			}
		}
		else if (PlayerHand.length() == 0) {
			if (Sidepile.length() < 3) {
				//computer wins
			}
			else {
				PlayerHand.enqueue(Sidepile.pop());
				PlayerHand.enqueue(Sidepile.pop());
				PlayerHand.enqueue(Sidepile.pop());
			}
		}
		WarStack.push(PlayerHand.dequeue()); //playerWarCard1
		WarStack.push(PlayerHand.dequeue()); //playerWarCard2
		WarStack.push(ComputerHand.dequeue()); //computerWarCard1
		WarStack.push(ComputerHand.dequeue()); //computerWarCard2

		Card playerContestCard = PlayerHand.dequeue();  //playerWarCard3
		Card computerContestCard = ComputerHand.dequeue(); //computerWarCard3

		if (playerContestCard.cardVal > computerContestCard.cardVal) {
			//player wins war
			PlayerHand.enqueue(playerContestCard);
			PlayerHand.enqueue(computerContestCard);
			while (!(WarStack.length() == 0)) {
				PlayerHand.enqueue(WarStack.pop());
			}
		}
		else if (playerContestCard.cardVal < computerContestCard.cardVal) {
			//computer wins war
			ComputerHand.enqueue(playerContestCard);
			ComputerHand.enqueue(computerContestCard);
			while (!(WarStack.length() == 0)) {
				ComputerHand.enqueue(WarStack.pop());
			}
		}
		else {
			//we need a war stack to handle all these extra cards before recursion
			WarStack.push(playerContestCard);
			WarStack.push(computerContestCard);
			war();
		} //double war
}

void initCardPile() {
		//not exactly sure where this would go but this would be the loop
		// w3schools.com/cpp/cpp_switch.asp

		for (int v = 2; v < 15; v++) {
			std::string name;
			std::string suit;
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
				if (s == 0) { suit = "Spades"; }
				else if (s == 1) { suit = "Hearts"; }
				else if (s == 2) { suit = "Clubs"; }
				else if (s == 3) { suit = "Diamonds"; }
				Card Card(name, suit, v);
				Drawpile.enqueue(Card); //depends on if we put this inside the queue or not
			}
		}
}

int main() {

	// constructors (i see this is python syntax)
	//drawpile = Drawpile();
	//playerHand = PlayerHand();
	//computerHand = ComputerHand();
	//sidePile = Sidepile();

	initCardPile(); //link just does to the function in this doc
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
