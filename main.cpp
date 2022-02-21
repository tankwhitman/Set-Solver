/*Name: Joshua Whitman		NetID:JSW625
  Date: 9/27/2020			Due:  9/27/2020
*/



#include "Card.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::istream;
using std::string;
using std::setw;
using std::vector;

bool getCard(istream& inFile, Card &card)											//given code
{
	string color;
	string shading;
	string shape;
	int count;

	if (inFile.eof()) { return false;}												//if file is ended

	inFile >> count;																//take count
	if (count < 1 || count > 3) { return false; }									//assign count
	card.setCount(count);
	inFile >> color;																//take color
	if (color == "red") { card.setColor(Card::RED); }								//assign color
	else if (color == "green") { card.setColor(Card::GREEN); }
	else if (color == "purple") { card.setColor(Card::PURPLE); }
	else { return false; }
	inFile >> shading;																//take shading
	if (shading == "filled") { card.setShading(Card::FILLED); }						//assign shading
	else if (shading == "open") { card.setShading(Card::OPEN); }
	else if (shading == "striped") { card.setShading(Card::STRIPED); }
	else { return false; }
	inFile >> shape;																//take shape
	if (shape == "oval") { card.setShape(Card::OVAL); }								//assign shape
	else if (shape == "diamond") { card.setShape(Card::DIAMOND); }					
	else if (shape == "squiggle") { card.setShape(Card::SQUIGGLE); }
	else { return false; }

	return true;
}




bool vectorAdd(istream& puzzle, vector<Card> &cardList) {							//creates a vector with all of the cards
		Card tempcard;
		if (getCard(puzzle, tempcard) == false) {									// calls getCard and creates an instance of a  card 
			return false;
		}
		cardList.push_back(tempcard);												//adds card to vector
		return true;
}

bool openFile(vector<Card>& cardList) {												//open if stream for file input
	ifstream puzzle;
	bool cert = true;
	string fileName;
	cout << "What is the name of the file?" << endl;
	cin >> fileName;																//input file name
	puzzle.open(fileName);															//attempts to open file
	if (puzzle.is_open()) {															//verifies file is open
		do {
			cert = vectorAdd(puzzle, cardList);										//takes file and feeds it to vectorAdd which helps create instances of Cards

		} while (cert == true);

		puzzle.close();																//closes file

		if (cert == true) {															//bool certificate to see if reading the file was successful
			return true;
		}
		else { return false; }
	}
	else {
		cout << "Could not open file. Please try again" << endl;
	}
	
}



void Solution(vector<Card> cardList) {												//solution function

	for (int i = 0; i < cardList.size(); i++)										// iterates through every possible combination of cards given
	{
		for (int j = i + 1; j < cardList.size(); j++)								//
		{
			for (int k = j + 1; k < cardList.size(); k++) 
			{
				if (cardList[i].isSet(cardList[j], cardList[k])) {					//calls isSet which will see if all three cards are apart of a set

					cout << cardList[i] << " " << cardList[j] << " " << cardList[k] <<  " " << endl; //output set
					cout << endl;
				}
			}
		}
	}

}

int main()
{
	string userIn;
	ifstream puzzle;
	vector<Card> cardList;

	do
	{
		cout << "Menu " << endl;																	// menu output 
		cout << "l - Load a Set puzzle from a file" << endl << "d - Display the set puzzle as a 3 x 4 matrix" << endl << "s - Display the solution for the Set puzzle" << endl;
		cout << "q - Quit" << endl;
		cin >> userIn;																				// menu input

		if (userIn == "l" || userIn == "d" || userIn == "s" || userIn == "q")						// verify that input is usable
		{
			if (userIn == "l")																		//load set puzzle
			{
				openFile(cardList);
				
			}

			if (userIn == "d")																		//display set puzzle
			{
				for (int i = 0; i < cardList.size(); i++) {
					Card m = cardList[i];
					cout << m << endl;
				}
			}

			if (userIn == "s") {																	//solve puzzle
				Solution(cardList);
			}
			

			if (userIn == "q") { cout << "Now exiting" << endl; }									// print exiting before exiting

		}
		else { cout << "Invalid option. Please try again. " << endl; }								// if userIn is invalid it will let the user know that it is.

	} while (userIn != "q");																		// do while loop so that the user can use the menu as many times as they want before entering "q" to quit.

	return 0;
}
