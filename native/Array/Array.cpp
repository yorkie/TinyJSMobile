#include "Array.h"
#include <cstdlib>

using namespace std;
using namespace JSM;

void Array::size(CScriptVar *c, void *) {
	int i = c->getParameter("this")->getArrayLength();
	c->getReturnVar()->setInt(i);
}

void Array::clear(CScriptVar *c, void *) {
	c->getParameter("this")->removeAllChildren();
}

