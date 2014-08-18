/**
 * Provides the implementation of the Definition class, which is really
 * nothing more than an ordered pair: a nonterminal attached to a string.
 */

#include "definition.h"
#include "random.h"

/**
 * Constructor: Definition
 * -----------------------
 * Constructs an instance of a Definition object based on the content of the specified file.
 */

Definition::Definition(ifstream& infile) {
	// your code here
	string str;
	infile >> str;

	nonterminal = str;

	while (str != "}") {
//		possibleExpansions = vector<Production>;
//		possibleExpansions = new vector<Production>;
		possibleExpansions.push_back(new Production<infile>);
	}

//	cout << endl << str << " ";
//	Production expension = new Production(infile);
//	this->nonterminal = "";
//	this->possibleExpansions = expension;
}

/**
 * Method: getRandomProduction
 * ---------------------------
 * Returns a const reference to one of the embedded Productions.
 */

const Production& Definition::getRandomProduction() const {
	// your code here
	return *(new Production()); // bogus
}
