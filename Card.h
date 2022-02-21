/*Name: Joshua Whitman		NetID:JSW625
  Date: 9/27/2020			Due:  9/27/2020
*/

#pragma once
#include <iostream>
#include <iomanip>
using std::ostream;
using std::setw;

class Card
{
private:
	// Define your member data below this comment
	int count;
	int color;
	int shading;
	int shape;

public:
	// Define a set of constants for the class
	// Don't touch these definitions, the code needs them
	static const int RED = 1;
	static const int GREEN = 2;
	static const int PURPLE = 3;
	static const int FILLED = 1;
	static const int OPEN = 2;
	static const int STRIPED = 3;
	static const int OVAL = 1;
	static const int SQUIGGLE = 2;
	static const int DIAMOND = 3;
	// here are a couple of operator overloads to make you life easier

	bool operator==(const Card& right) { return isEqual(right); }
	friend ostream& operator<<(ostream& os, const Card& card);

	// your methods should be defined below this comment
	Card();													//
	Card(int count, int color, int shading, int shape);		//set card values
	void setCount(int count);								//set count
	void setColor(int color);								//set color
	void setShading(int shading);							//set shading
	void setShape(int shape);								//set shape

	int getCount();			//GETTERS						//get count
	int getColor();											//get color
	int getShading();										//get shading
	int getShape();											//get shape

	Card completeSet(const Card& second);					//define completeSet
	bool isSet(const Card& second, const Card& third);		//define isSet
	bool isEqual(const Card& second);						//define isEqual


};

