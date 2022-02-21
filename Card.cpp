/*Name: Joshua Whitman		NetID:JSW625
  Date: 9/27/2020			Due:  9/27/2020
*/

#include "Card.h"


// this is the definition for overloading the << operation
// use it as follows
// Card m;
// cout << "This is your card: " << m << endl;
ostream& operator<<(ostream& os, const Card& card)
{
	os << card.count;
	if (card.color == Card::RED) { os << setw(7) << "red"; }
	else if (card.color == Card::GREEN) { os << setw(7) << "green"; }
	else if (card.color == Card::PURPLE) { os << setw(7) << "purple"; }

	if (card.shading == Card::OPEN) { os << setw(8) << "open"; }
	else if (card.shading == Card::FILLED) { os << setw(8) << "filled"; }
	else if (card.shading == Card::STRIPED) { os << setw(8) << "striped"; }

	if (card.shape == Card::OVAL) { os << setw(9) << "oval"; }
	else if (card.shape == Card::DIAMOND) { os << setw(9) << "diamond"; }
	else if (card.shape == Card::SQUIGGLE) { os << setw(9) << "squiggle"; }
	return os;
}

// place the your code below this line.

Card::Card() {														//default
	count = -1;
	color = -1;
	shading = -1;
	shape = -1;
}

Card::Card(int count, int color, int shading, int shape) {			//set card
	setCount(count);
	setColor(color);
	setShading(shading);
	setShape(shape);

}

	void Card::setCount(int count) {								//set count
		this->count = count;
	}
	void Card::setColor(int color) {								//set color
		this->color = color;
	}
	void Card::setShading(int shading) {							//set shading
		this->shading = shading;
	}
	void Card::setShape(int shape) {								//set shape
		this->shape = shape;
	}

	int Card::getCount() {											//get count
		return count;
	}
	int Card::getColor() {											//get color
		return color;
	}
	int Card::getShading() {										//get shading
		return shading;	
	}
	int Card::getShape() {											//get shape
		return shape;
	}


	Card Card::completeSet(const Card& second){						//will see what what the third card should be if it were to be a set

		int newCount;
		if (count == second.count) {								//sets count.. if equal, then equal
			newCount = count;
		}
		else {														//if not equal, sets count to the number not already in use
			newCount = 6 - count - second.count;
		}

		int newColor;												//set color
		if (color == second.color) {
			newColor = color;
		}
		else {														//if not equal, sets color to color not already in use
			newColor = 6 - color - second.color;
		}

		int newShading;												//set shading
		if (shading == second.shading) {
			newShading = shading;
		}
		else {														//if not equal, sets shading to shading not already in use
			newShading = 6 - shading - second.shading;
		}

		int newShape;												//set shape
		if (shape == second.shape) {
			newShape = shape;
		}
		else {														//if not equal, sets shape to shape not already in use
			newShape = 6 - shape - second.shape;
		}

		return Card(newCount, newColor, newShading, newShape);		//return
	}
	bool Card::isSet(const Card& second, const Card& third) {		//sees if 3 cards are a set
		Card tempcard = completeSet(second);						//sets a temp card to what ideal card should be
		if (tempcard == third){										//if ideal is equal to reality -> true
			return true;
		}
		else { return false; }
	}
	bool Card::isEqual(const Card& second) {						// sees if all attributes of 2 cards are equal
		if (count == second.count && color == second.color && shape == second.shape && shading == second.shading) {
			return true;
		}
		else {
			return false;
		}
	}


