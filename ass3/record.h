#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "utility.h"

/* Database enums
 * --------------
 * Ideally, these enums would be declared inside the scope of
 * the Database class, but it turns out gcc doesn't not handle
 * nested enums inside a template class very well, so you will 
 * want to define that at the top-level scope as a workaround.
 */

enum DBSelectOperation {
	All, Clear, Add, Remove, Refine
};
enum DBScope {
	AllRecords, SelectedRecords
};
enum DBQueryOperator {
	Equal, NotEqual, LessThan, GreaterThan
};

// Need to add declarations for operator<< and operator >> here
template<class > class Record;
template<class value> ostream& operator<<(ostream& out, const Record<value>& r);
template<class value> istream& operator>>(istream& in, Record<value>& r);

template<class value>
class Record {
public:
	friend ostream& operator<<<value>(ostream& out, const Record<value>& r);
	friend istream& operator>><value>(istream& in, Record<value>& r);

	Record() :_isSelected(false) {};
	~Record() {};

	bool isSelected() const;
	void setSelected(bool val);
	bool matchesQuery(const string& attr, DBQueryOperator op,
			const value& want) const;

private:
	bool _isSelected;
	vector<pair<string, value>> record;
};

#include "record.tem"

#endif