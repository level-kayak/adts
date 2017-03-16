#include "StackL.h"
using namespace std;

int Stack::size()
{
	return data.size();
}

void Stack::push(int val)
{
	data.insert(val,1);
}

void Stack::pop()
{
	data.remove(1);
}

int Stack::top()
{
	return data.get(1);
}

void Stack::clear()
{
	data.~List();
}
