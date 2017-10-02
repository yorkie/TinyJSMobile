#include "JSON.h"
#include <cstdlib>

using namespace std;
using namespace JSM;

void JSON::stringify(CScriptVar *c, void *userdata) {
	IGNORE_PARAMETER(userdata);
	string result;
	c->getParameter("obj")->getJSON(result);
	c->getReturnVar()->setString(result.c_str());
}

void JSON::parse(CScriptVar *c, void *userdata) {
	CTinyJS *tinyJS = (CTinyJS *)userdata;
	c->setReturnVar(tinyJS->evaluateComplex(c->getParameter("src")->getString()).var);
}

