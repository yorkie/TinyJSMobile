#include <math.h>
#include <cstdlib>
#include <sstream>
#include "Math.h"

using namespace std;
using namespace JSM;

#define k_E                 ::exp(1.0)
#define k_PI                3.1415926535897932384626433832795

#define F_ABS(a)            ((a)>=0 ? (a) : (-(a)))
#define F_MIN(a,b)          ((a)>(b) ? (b) : (a))
#define F_MAX(a,b)          ((a)>(b) ? (a) : (b))
#define F_SGN(a)            ((a)>0 ? 1 : ((a)<0 ? -1 : 0 ))
#define F_RNG(a,min,max)    ((a)<(min) ? min : ((a)>(max) ? max : a ))
#define F_ROUND(a)          ((a)>0 ? (int) ((a)+0.5) : (int) ((a)-0.5) )

//CScriptVar shortcut macro
#define scIsInt(a)          ( c->getParameter(a)->isInt() )
#define scIsDouble(a)       ( c->getParameter(a)->isDouble() )  
#define scGetInt(a)         ( c->getParameter(a)->getInt() )
#define scGetDouble(a)      ( c->getParameter(a)->getDouble() )  
#define scReturnInt(a)      ( c->getReturnVar()->setInt(a) )
#define scReturnDouble(a)   ( c->getReturnVar()->setDouble(a) )  

//Math.abs(x) - returns absolute of given value
void Math::abs(CScriptVar *c, void *userdata) {
	if ( scIsInt("a") ) {
		scReturnInt( F_ABS( scGetInt("a") ) );
	} else if ( scIsDouble("a") ) {
		scReturnDouble( F_ABS( scGetDouble("a") ) );
	}
}

//Math.round(a) - returns nearest round of given value
void Math::round(CScriptVar *c, void *userdata) {
	if ( scIsInt("a") ) {
		scReturnInt( F_ROUND( scGetInt("a") ) );
	} else if ( scIsDouble("a") ) {
		scReturnDouble( F_ROUND( scGetDouble("a") ) );
	}
}

//Math.min(a,b) - returns minimum of two given values 
void Math::min(CScriptVar *c, void *userdata) {
	if ( (scIsInt("a")) && (scIsInt("b")) ) {
		scReturnInt( F_MIN( scGetInt("a"), scGetInt("b") ) );
	} else {
		scReturnDouble( F_MIN( scGetDouble("a"), scGetDouble("b") ) );
	}
}

//Math.max(a,b) - returns maximum of two given values  
void Math::max(CScriptVar *c, void *userdata) {
	if ( (scIsInt("a")) && (scIsInt("b")) ) {
		scReturnInt( F_MAX( scGetInt("a"), scGetInt("b") ) );
	} else {
		scReturnDouble( F_MAX( scGetDouble("a"), scGetDouble("b") ) );
	}
}

//Math.range(x,a,b) - returns value limited between two given values  
void Math::range(CScriptVar *c, void *userdata) {
	if ( (scIsInt("x")) ) {
		scReturnInt( F_RNG( scGetInt("x"), scGetInt("a"), scGetInt("b") ) );
	} else {
		scReturnDouble( F_RNG( scGetDouble("x"), scGetDouble("a"), scGetDouble("b") ) );
	}
}

//Math.sign(a) - returns sign of given value (-1==negative,0=zero,1=positive)
void Math::sign(CScriptVar *c, void *userdata) {
	if ( scIsInt("a") ) {
		scReturnInt( F_SGN( scGetInt("a") ) );
	} else if ( scIsDouble("a") ) {
		scReturnDouble( F_SGN( scGetDouble("a") ) );
	}
}

//Math.PI() - returns PI value
void Math::PI(CScriptVar *c, void *userdata) {
	scReturnDouble(k_PI);
}

//Math.toDegrees(a) - returns degree value of a given angle in radians
void Math::toDegrees(CScriptVar *c, void *userdata) {
	scReturnDouble( (180.0/k_PI)*( scGetDouble("a") ) );
}

//Math.toRadians(a) - returns radians value of a given angle in degrees
void Math::toRadians(CScriptVar *c, void *userdata) {
	scReturnDouble( (k_PI/180.0)*( scGetDouble("a") ) );
}

//Math.sin(a) - returns trig. sine of given angle in radians
void Math::sin(CScriptVar *c, void *userdata) {
	scReturnDouble(::sin( scGetDouble("a") ) );
}

//Math.asin(a) - returns trig. arcsine of given angle in radians
void Math::asin(CScriptVar *c, void *userdata) {
	scReturnDouble(::asin( scGetDouble("a") ) );
}

//Math.cos(a) - returns trig. cosine of given angle in radians
void Math::cos(CScriptVar *c, void *userdata) {
	scReturnDouble(::cos( scGetDouble("a") ) );
}

//Math.acos(a) - returns trig. arccosine of given angle in radians
void Math::acos(CScriptVar *c, void *userdata) {
	scReturnDouble(::acos( scGetDouble("a") ) );
}

//Math.tan(a) - returns trig. tangent of given angle in radians
void Math::tan(CScriptVar *c, void *userdata) {
	scReturnDouble(::tan( scGetDouble("a") ) );
}

//Math.atan(a) - returns trig. arctangent of given angle in radians
void Math::atan(CScriptVar *c, void *userdata) {
	scReturnDouble(::atan( scGetDouble("a") ) );
}

//Math.sinh(a) - returns trig. hyperbolic sine of given angle in radians
void Math::sinh(CScriptVar *c, void *userdata) {
	scReturnDouble(::sinh( scGetDouble("a") ) );
}

//Math.asinh(a) - returns trig. hyperbolic arcsine of given angle in radians
void Math::asinh(CScriptVar *c, void *userdata) {
	scReturnDouble(::asinh( scGetDouble("a") ) );
}

//Math.cosh(a) - returns trig. hyperbolic cosine of given angle in radians
void Math::cosh(CScriptVar *c, void *userdata) {
	scReturnDouble(::cosh( scGetDouble("a") ) );
}

//Math.acosh(a) - returns trig. hyperbolic arccosine of given angle in radians
void Math::acosh(CScriptVar *c, void *userdata) {
	scReturnDouble(::acosh( scGetDouble("a") ) );
}

//Math.tanh(a) - returns trig. hyperbolic tangent of given angle in radians
void Math::tanh(CScriptVar *c, void *userdata) {
	scReturnDouble(::tanh( scGetDouble("a") ) );
}

//Math.atan(a) - returns trig. hyperbolic arctangent of given angle in radians
void Math::atanh(CScriptVar *c, void *userdata) {
	scReturnDouble(::atan( scGetDouble("a") ) );
}

//Math.E() - returns E Neplero value
void Math::E(CScriptVar *c, void *userdata) {
	scReturnDouble(k_E);
}

//Math.log(a) - returns natural logaritm (base E) of given value
void Math::log(CScriptVar *c, void *userdata) {
	scReturnDouble(::log( scGetDouble("a") ) );
}

//Math.log10(a) - returns logaritm(base 10) of given value
void Math::log10(CScriptVar *c, void *userdata) {
	scReturnDouble(::log10( scGetDouble("a") ) );
}

//Math.exp(a) - returns e raised to the power of a given number
void Math::exp(CScriptVar *c, void *userdata) {
	scReturnDouble(::exp( scGetDouble("a") ) );
}

//Math.pow(a,b) - returns the result of a number raised to a power (a)^(b)
void Math::pow(CScriptVar *c, void *userdata) {
	scReturnDouble(::pow( scGetDouble("a"), scGetDouble("b") ) );
}

//Math.sqr(a) - returns square of given value
void Math::sqr(CScriptVar *c, void *userdata) {
	scReturnDouble( ( scGetDouble("a") * scGetDouble("a") ) );
}

//Math.sqrt(a) - returns square root of given value
void Math::sqrt(CScriptVar *c, void *userdata) {
	scReturnDouble( sqrtf( scGetDouble("a") ) );
}

//Math.rand() - returns random double number
void Math::rand(CScriptVar *c, void *userdata) {

	scReturnDouble((double)::rand()/RAND_MAX);
}

//Math.randInt(min, max) - returns random int number
void Math::randInt(CScriptVar *c, void *userdata) {
	int min = c->getParameter("min")->getInt();
	int max = c->getParameter("max")->getInt();
	int val = min + (int)(::rand()%(1+max-min));
	scReturnInt(val);
}



