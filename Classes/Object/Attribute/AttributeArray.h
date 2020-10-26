#ifndef _AttributeArray_h_
#define _AttributeArray_h_

#include <iostream>
#include <map>
class AttributeModule;
class AttributeArray {
public:
	void add(AttributeModule * att);
	void remove(AttributeModule* att);
private:
	std::map<int, AttributeModule*> m_list;
};




#endif // !_AttributeArray_h_



