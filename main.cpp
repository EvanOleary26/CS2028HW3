#include "Queue.h"
#include "Node.h"
#include "Stack.h"
#include "Exceptions.h"
#include "Card.h"
#include "List.h"

#include <iostream>
#include <string>
#include <random>

Stack<Card> Sidepile{};
Queue<Card> PlayerHand{};
Queue<Card> ComputerHand{};
List<Card> Drawpile{};
Stack<Card> WarStack(8);

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
	/*
	std::cout << "	Player card 1: " << playerCard1.display() << std::endl;
	std::cout << "	Player card 2: " << playerCard2.display() << std::endl;
	std::cout << "	Player card 3: " << playerCard3.display() << std::endl;

	std::cout << "	Computer card 1: " << computerCard1.display() << std::endl;
	std::cout << "	Computer card 2: " << computerCard2.display() << std::endl;
	std::cout << "	Computer card 3: " << computerCard3.display() << std::endl;
	*/
	int ComputerCardSum = computerCard1.cardVal + computerCard2.cardVal + computerCard3.cardVal;
	int PlayerCardSum = playerCard1.cardVal + playerCard2.cardVal + playerCard3.cardVal;

	WarStack.push(playerCard1);
	WarStack.push(playerCard2);
	WarStack.push(playerCard3);
	WarStack.push(computerCard1); //we need the warstack to be more than five. getting an overflow here when we go to war
	WarStack.push(computerCard2);
	WarStack.push(computerCard3);


	//WarStack.displayStack();

	if (PlayerCardSum > ComputerCardSum) {
		//player wins war
		while (WarStack.length() != 0) {
			//std::cout << "		Adding " << WarStack.top().display() << " to the player's hand." << std::endl;
			PlayerHand.enqueue(WarStack.pop());
		}
		std::cout << "Congrats you won the war!" << std::endl;
	}
	else {
		//computer wins war
		while (WarStack.length() != 0) {
			//std::cout << "		Adding " << WarStack.top().display() << " to the computer's hand." << std::endl;
			ComputerHand.enqueue(WarStack.pop());
		}
		std::cout << "The Computer won the war." << std::endl;
	}
}

void round(int& turns) {
	Card playerCard = PlayerHand.dequeue();
	Card computerCard = ComputerHand.dequeue();
	// show player their card and give them their options (stack or play)
	int playOption = 0;
 	std::cout << "Your card is the " << playerCard.display()<<std::endl;
	std::cout << "1. Play\n2. Stack\n3. Show Deck" << std::endl;
	std::cout << "	Player hand size: " << PlayerHand.length() << std::endl;
	std::cout << "	Computer hand size: " << ComputerHand.length() << std::endl;
	std::cin >> playOption;

	while (!(playOption == 1 || playOption == 2 || playOption == 3)) {
		std::cout << "Please enter a valid option" << std::endl;
		std::cin >> playOption;
	}
	if (playOption == 3) {
		PlayerHand.displayQueue();
	}

	if (playOption == 2) {
		Sidepile.push(playerCard);
		playerCard = PlayerHand.dequeue(); //new card that must be played
		std::cout << "Player has stacked their card." << std::endl;
		if (Sidepile.length() > 1){
			std::cout << "There are now " << Sidepile.length() << " cards in your side pile" << std::endl;
		} else {
			std::cout << "There is now " << Sidepile.length() << " card in your side pile" << std::endl;
		}
		std::cout << "The new card is the " << playerCard.display() << std::endl;
	}
	if (playerCard.cardVal > computerCard.cardVal) {
		PlayerHand.enqueue(playerCard);
		PlayerHand.enqueue(computerCard);
		std::cout << "Computer had a " << computerCard.display() << ". Player gets the cards. " << std::endl;
	}
	else if (playerCard.cardVal < computerCard.cardVal) {
		ComputerHand.enqueue(playerCard);
		ComputerHand.enqueue(computerCard);
		std::cout << "Computer had a " << computerCard.display() << ". Computer gets the cards. " << std::endl;
	}
	else { //if the cards are equal //this can be looped somehow
		WarStack.push(playerCard);
		WarStack.push(computerCard);
		std::cout << "Computer had a " << computerCard.display() << ". WAR!!. " << std::endl;
		war();
	}
	turns++;
}

void initCardPile(List<Card>& Drawpile) {
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
			Drawpile.AddItem(*tempCard);
		}
	}
}

void shuffle(List<Card>& Drawpile, Queue<Card>& PlayerHand, Queue<Card>& ComputerHand) {
	//Currently not working will come back to work on this

	int pileSize = Drawpile.Size();   //Get size of Draw pile

	//Create a random number between 0 and size of Drawpile
	std::random_device rd;
	std::mt19937 gen(rd());

	bool addToPlayerHand = true;

	while (pileSize != 0) {
		std::uniform_int_distribution<> distrib(0, pileSize - 1);
		int randomValue = distrib(gen);
		//std::cout << "The size of the pile " << pileSize << std::endl;
		//std::cout << "Looking for card at index " << randomValue << std::endl;
		if (addToPlayerHand) {
			PlayerHand.enqueue(Drawpile.GetItemAt(randomValue));
			addToPlayerHand = false;
		}
		else {
			ComputerHand.enqueue(Drawpile.GetItemAt(randomValue));
			addToPlayerHand = true;
		}
		pileSize = Drawpile.Size();
	}
}

int main() {

	//constructors (i see this is python syntax)
	//drawpile = Drawpile();
	//playerHand = PlayerHand();
	//computerHand = ComputerHand();
	//sidePile = Sidepile();
	try {
		initCardPile(Drawpile); 

	
		shuffle(Drawpile, PlayerHand, ComputerHand);//shuffle function
		/*
		int count = 1;
		std::cout << "Player Hand: " << std::endl;
		std::cout << "Size: " << PlayerHand.length() << std::endl;
		while (!PlayerHand.isEmpty()) {
			std::cout << count << ": " << PlayerHand.dequeue().display() << std::endl;
			count++;
		}

		count = 1;
		std::cout << "\nComputer Hand: " << std::endl;
		std::cout << "Size: " << ComputerHand.length() << std::endl;
		while (!ComputerHand.isEmpty()) {
			std::cout << count << ": " << ComputerHand.dequeue().display() << std::endl;
			count++;
		}
		*/
	

		bool handIsEmpty = false;
		int turns = 0;

		while (!handIsEmpty) {
			std::cout << "Round " << turns << std::endl;
			round(turns);
			if (PlayerHand.isEmpty() || ComputerHand.isEmpty()) {
				handIsEmpty = true;
				break;
			}
		}
	}
	catch (Exception& e) {
		std::cout << e.errorMessage << " : " << e.errorNumber << std::endl;
	}

	return 0;
}