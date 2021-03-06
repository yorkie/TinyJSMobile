#ifndef JSM_MD5
#define JSM_MD5

#include "../ClassLoader.h"

namespace JSM {

	class JSMD5 : public JSClass {
		static std::string hashString(const unsigned char* s, unsigned int size);

		static std::string hashHex(const unsigned char* s, unsigned int size);

		static void hashString(CScriptVar *c, void *);

		static void hashHex(CScriptVar *c, void *);

		protected:
		inline void registerFunctions(CTinyJS* tinyJS, const std::string& className) {
			addFunction(tinyJS, className, "hashString(src)", hashString, NULL);
			addFunction(tinyJS, className, "hashHex(src)", hashHex, NULL);
		}

		public:
		DECL_INSTANCE(JSMD5)
	};

};

#endif
