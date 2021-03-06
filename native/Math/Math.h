#ifndef TINYJS_MATHFUNCTIONS_H
#define TINYJS_MATHFUNCTIONS_H

#include "../ClassLoader.h"


namespace JSM {

	class Math : public JSClass {
		//Math.abs(x) - returns absolute of given value
		static void abs(CScriptVar *c, void *userdata);

		//Math.round(a) - returns nearest round of given value
		static void round(CScriptVar *c, void *userdata);

		//Math.min(a,b) - returns minimum of two given values 
		static void min(CScriptVar *c, void *userdata);

		//Math.max(a,b) - returns maximum of two given values  
		static void max(CScriptVar *c, void *userdata);

		//Math.range(x,a,b) - returns value limited between two given values  
		static void range(CScriptVar *c, void *userdata);

		//Math.sign(a) - returns sign of given value (-1==negative,0=zero,1=positive)
		static void sign(CScriptVar *c, void *userdata);

		//Math.PI() - returns PI value
		static void PI(CScriptVar *c, void *userdata);

		//Math.toDegrees(a) - returns degree value of a given angle in radians
		static void toDegrees(CScriptVar *c, void *userdata);

		//Math.toRadians(a) - returns radians value of a given angle in degrees
		static void toRadians(CScriptVar *c, void *userdata);

		//Math.sin(a) - returns trig. sine of given angle in radians
		static void sin(CScriptVar *c, void *userdata);

		//Math.asin(a) - returns trig. arcsine of given angle in radians
		static void asin(CScriptVar *c, void *userdata);

		//Math.cos(a) - returns trig. cosine of given angle in radians
		static void cos(CScriptVar *c, void *userdata);

		//Math.acos(a) - returns trig. arccosine of given angle in radians
		static void acos(CScriptVar *c, void *userdata);

		//Math.tan(a) - returns trig. tangent of given angle in radians
		static void tan(CScriptVar *c, void *userdata);

		//Math.atan(a) - returns trig. arctangent of given angle in radians
		static void atan(CScriptVar *c, void *userdata);

		//Math.sinh(a) - returns trig. hyperbolic sine of given angle in radians
		static void sinh(CScriptVar *c, void *userdata);

		//Math.asinh(a) - returns trig. hyperbolic arcsine of given angle in radians
		static void asinh(CScriptVar *c, void *userdata);

		//Math.cosh(a) - returns trig. hyperbolic cosine of given angle in radians
		static void cosh(CScriptVar *c, void *userdata);

		//Math.acosh(a) - returns trig. hyperbolic arccosine of given angle in radians
		static void acosh(CScriptVar *c, void *userdata);

		//Math.tanh(a) - returns trig. hyperbolic tangent of given angle in radians
		static void tanh(CScriptVar *c, void *userdata);

		//Math.atan(a) - returns trig. hyperbolic arctangent of given angle in radians
		static void atanh(CScriptVar *c, void *userdata);

		//Math.E() - returns E Neplero value
		static void E(CScriptVar *c, void *userdata);

		//Math.log(a) - returns natural logaritm (base E) of given value
		static void log(CScriptVar *c, void *userdata);

		//Math.log10(a) - returns logaritm(base 10) of given value
		static void log10(CScriptVar *c, void *userdata);

		//Math.exp(a) - returns e raised to the power of a given number
		static void exp(CScriptVar *c, void *userdata);

		//Math.pow(a,b) - returns the result of a number raised to a power (a)^(b)
		static void pow(CScriptVar *c, void *userdata);

		//Math.sqr(a) - returns square of given value
		static void sqr(CScriptVar *c, void *userdata);

		//Math.sqrt(a) - returns square root of given value
		static void sqrt(CScriptVar *c, void *userdata);

		//Math.rand() - returns random double number
		static void rand(CScriptVar *c, void *userdata);

		//Math.randInt(min, max) - returns random int number
		static void randInt(CScriptVar *c, void *userdata);

		protected:
		void registerFunctions(CTinyJS *tinyJS, const std::string& className) {
			// --- Math and Trigonometry functions ---
			addFunction(tinyJS, className, "abs(a)", Math::abs, 0);
			addFunction(tinyJS, className, "round(a)", Math::round, 0);
			addFunction(tinyJS, className, "min(a,b)", Math::min, 0);
			addFunction(tinyJS, className, "max(a,b)", Math::max, 0);
			addFunction(tinyJS, className, "range(x,a,b)", Math::range, 0);
			addFunction(tinyJS, className, "sign(a)", Math::sign, 0);

			addFunction(tinyJS, className, "PI()", Math::PI, 0);
			addFunction(tinyJS, className, "toDegrees(a)", Math::toDegrees, 0);
			addFunction(tinyJS, className, "toRadians(a)", Math::toRadians, 0);
			addFunction(tinyJS, className, "sin(a)", Math::sin, 0);
			addFunction(tinyJS, className, "asin(a)", Math::asin, 0);
			addFunction(tinyJS, className, "cos(a)", Math::cos, 0);
			addFunction(tinyJS, className, "acos(a)", Math::acos, 0);
			addFunction(tinyJS, className, "tan(a)", Math::tan, 0);
			addFunction(tinyJS, className, "atan(a)", Math::atan, 0);
			addFunction(tinyJS, className, "sinh(a)", Math::sinh, 0);
			addFunction(tinyJS, className, "asinh(a)", Math::asinh, 0);
			addFunction(tinyJS, className, "cosh(a)", Math::cosh, 0);
			addFunction(tinyJS, className, "acosh(a)", Math::acosh, 0);
			addFunction(tinyJS, className, "tanh(a)", Math::tanh, 0);
			addFunction(tinyJS, className, "atanh(a)", Math::atanh, 0);

			addFunction(tinyJS, className, "E()", Math::E, 0);
			addFunction(tinyJS, className, "log(a)", Math::log, 0);
			addFunction(tinyJS, className, "log10(a)", Math::log10, 0);
			addFunction(tinyJS, className, "exp(a)", Math::exp, 0);
			addFunction(tinyJS, className, "pow(a,b)", Math::pow, 0);

			addFunction(tinyJS, className, "sqr(a)", Math::sqr, 0);
			addFunction(tinyJS, className, "sqrt(a)", Math::sqrt, 0);    
			addFunction(tinyJS, className, "rand()", Math::rand, 0);
			addFunction(tinyJS, className, "randInt(min, max)", Math::randInt, 0);    
		}

		public:
		DECL_INSTANCE(Math)
	};

};


#endif
