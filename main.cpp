/*********************************************************************  
** Program Filename: main.cpp
** Author: Eric Podolsky   
** Date: 21 May 2016
** Description: A turn-based game involving two teams of user-specified size.
                It includes a battle system between a pair of creatures,
                which may be one of five types (whose stats are listed).
				The creatures are chosen by the user, and then the battle
				proceeds automatically. When a team has run out of living
				creatures, the game is over and the opposing team wins. The
				leaderboard is then outputted based on the order of elimination.
** Input: Console
** Output: Console
*********************************************************************/


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "Medusa.hpp"
#include "Potter.hpp"
#include "Bluemen.hpp"
#include "Barbarian.hpp"
#include "BabaYaga.hpp"
#include "utilities.hpp"
#include "Queue.hpp"
#include "Stack.hpp"

void menu();
void assign(int choice, Creature*& player);
void match(Queue& team1, Queue& team2);
Creature* fight(Creature* p1, Creature *p2);

int main() {
	srand(time(NULL));
	menu();

	return 0;
}

/*********************************************************************  
** Function: menu()
** Description: Input users' creature choices for both teams and begins the battle
** Parameters:
** Pre-Conditions: "Creature.hpp", "utilities.hpp", <iostream>
** Post-Conditions:
*********************************************************************/ 
void menu() {
	int teamSize, choice1, choice2;
	
	std::cout << "How many players would you like on each team? ";
	std::cin >> teamSize;
	checkPositive(teamSize);
	
	Creature *p1, *p2;
	Queue t1, t2;
	std::string name;
	
	std::cout << "1. Barbarian (12 HP, 0 armor, 2d6 attack, 2d6 defense)" << std::endl;
	std::cout << "2. Baba Yaga (12 HP, 3 armor, 2d6 attack, 1d10 defense)" << std::endl;
	std::cout << "3. Harry Potter (10 HP, 0 armor, 2d6 attack, 2d6 defense)" << std::endl;
	std::cout << "4. Blue Men (12 HP, 3 armor, 2d10 attack, 3d6 defense)" << std::endl;
	std::cout << "5. Medusa (8 HP, 3 armor, 2d6 attack, 1d6 defense)" << std::endl;
	
	for(int i = 1; i <= teamSize; ++i) {
		std::cout << "Choose player " << i << " for team 1: ";
		std::cin >> choice1;
		checkRange(choice1, 1, 5);
		
		assign(choice1, p1);
		p1 -> set_team(1);
		std::cin.ignore(255, '\n');
		std::cout << "What would you like to name it? ";
		getline(std::cin, name);
		p1->set_firstName(name);
		
		t1.add(p1);
	}
	
	for(int i = 1; i <= teamSize; ++i) {
		std::cout << "Choose player " << i << " for team 2: ";
		std::cin >> choice2;
		checkRange(choice2, 1, 5);
		assign(choice2, p2);
		p2->set_team(2);
		std::cin.ignore(255, '\n');
		std::cout << "What would you like to name it? ";
		getline(std::cin, name);
		p2->set_firstName(name);
		
		t2.add(p2);
	}

	match(t1, t2);
	
	std::cout << std::endl;
	
}

/*********************************************************************  
** Function: assign(int, Creature*&)
** Description: Based on which number was chosen (see menu()), the 
                correct type of creature is assigned to the given player
** Parameters: choice - the number of the creature
               player - the pointer to the given creature
** Pre-Conditions: "Creature.hpp", choice has been checked to be 1-5
** Post-Conditions: the player pointer now points to a specific type of creature
*********************************************************************/ 
void assign(int choice, Creature*& player) {
	switch(choice) {
		case 1: {
			player = new Barbarian;
			break;
		}
		case 2: {
			player = new BabaYaga;
			break;
		}
		case 3: {
			player = new Potter;	
			break;
		}
		case 4: {
			player = new Bluemen;
			break;
		}
		case 5: {
			player = new Medusa;
			break;
		}
	}
}

/*********************************************************************  
** Function: match(Queue&, Queue&)
** Description: Starts a match between two teams consisting of Creature pointers,
                then displays the final scores for each team (the total number of wins)
				and the leaderboard
** Parameters: team1, team2 - the competing teams
** Pre-Conditions: "Queue.hpp"
** Post-Conditions:
*********************************************************************/ 
void match(Queue& team1, Queue& team2) {
	char yn;
	Stack leaderboard;
	Creature *p1, *p2, *winner;
	int t1score = 0;
	int t2score = 0;
	int round = 0;
	
	while(!team1.isEmpty() && !team2.isEmpty()) {
		++round;
		p1 = team1.remove();
		p2 = team2.remove();
		std::cout << "Round " << round << std::endl;
		std::cout << "Player 1: " << p1->getName() << std::endl;
		std::cout << "Player 2: " << p2->getName() << std::endl << std::endl;
		winner = fight(p1, p2);
		if(winner == p1) {
			++t1score;
			team1.add(p1);
			leaderboard.add(p2);
			std::cout << "Winner: " << p1->getName() << std::endl;
		}
		else {
			++t2score;
			team2.add(p2);
			leaderboard.add(p1);
			std::cout << "Winner: " << p2->getName() << std::endl;
		}
		std::cout << std::endl;
		std::cout << "Scores (based on number of wins):" << std::endl;
		std::cout << "Team 1: " << t1score << ", Team 2: " << t2score << std::endl << std::endl;
	
	}
	

	
	if(team1.isEmpty()) {
		while(!team2.isEmpty()) {
			leaderboard.add(team2.remove());
		}
		std::cout << "Team 1 is out of players. Team 2 wins!" << std::endl;
	}
	else {
		while(!team1.isEmpty()) {
			leaderboard.add(team1.remove());
		}
		std::cout << "Team 2 is out of players. Team 1 wins!" << std::endl;
	}

	std::cout << "Here is the leaderboard: " << std::endl;
	int position = 1;
	Creature* tmp;
	for(; position <= 3 && !leaderboard.isEmpty(); ++position) {
		tmp = leaderboard.remove();
		std::cout << position << ". ";
		std::cout << tmp->getName() << " of Team " << tmp->get_team() << std::endl;
		delete tmp;
	}
	if(!leaderboard.isEmpty()) {
		std::cout << "Would you like to see the rest of the leaderboard? (y/n) ";
		std::cin >> yn;
		checkYN(yn);
	}
	
	while(!leaderboard.isEmpty()) {
		tmp = leaderboard.remove();
		if(yn == 'y' || yn == 'Y') {
			std::cout << position << ". ";
			std::cout << tmp->getName() << " of Team " << tmp->get_team() << std::endl;
		}
		delete tmp;
		++position;
	}
}

/*********************************************************************  
** Function: fight(Creature*, Creature*)
** Description: Fights the two creatures until one has strength <= 0
** Parameters: p1, p2 - pointers to the two opponents
** Pre-Conditions: "Creature.hpp", the pointers point to a derived class of Creature
** Post-Conditions: a winner is declared to the console and returned
*********************************************************************/ 
Creature* fight(Creature* p1, Creature *p2) {
	while(p1->getStrength() > 0 && p2->getStrength() > 0) {
		std::cout << p1->getName() << "'s turn" << std::endl;
		p1->attack(p2);
		std::cout << std::endl;
		if(p2->getStrength() > 0) {
			std::cout << p2->getName() << "'s turn" << std::endl;
			p2->attack(p1);
			std::cout << std::endl;
		}
	}
	if(p1->getStrength() <= 0) {
		std::cout << p2->getName() << " wins!" << std::endl;
		p2->restore();
		return p2;
	}
	else {
		std::cout << p1->getName() << " wins!" << std::endl;
		p1->restore();
		return p1;
	}
}