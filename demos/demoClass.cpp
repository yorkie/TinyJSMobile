#include "../native/ClassLoader.h"

//demo how to implement native class
class MyNativeClass {
		int i;
	public:
		void test(CScriptVar* var, void* data) {
			printf("NativeClass test function %d.%d\r\n", (*(int*)data)++, i++);
		}

		MyNativeClass(void *p) {
			i = 0;
		}	
};

static int _count = 0;

template<class T> class MyNativeClassLoader : public NativeClassLoader<T> {

	MAP_FUNC(test)

	protected:
		void registerFunctions(CTinyJS* tinyJS, const std::string& className) {
			JSClass::addFunction(tinyJS, className, "test()", test, (void*)&_count);
		}

	public:
		DECL_INSTANCE(MyNativeClassLoader)
};

//demo how to implement regular class
class MyClass : public JSClass {
	static void test(CScriptVar* var, void* data) {
		printf("Regular class test function %d.\r\n", (*(int*)data)++);
	}	

	protected:
	void registerFunctions(CTinyJS* tinyJS, const std::string& className) {
		addFunction(tinyJS, className, "test()", test, (void*)&_count);
	}

	public:
	DECL_INSTANCE(MyClass)
};


static void moduleLoader(CTinyJS* tinyJS) {
	MyClass::instance().load(tinyJS, "MyClass");
	MyNativeClassLoader<MyNativeClass>::instance().load(tinyJS, "MyNativeClass");
}



int main(int argc, char** argv) {

	while(true) { //Don't be scared, just for memory test:P.
		CTinyJS tinyJS;

		tinyJS.loadModule(moduleLoader);

		tinyJS.exec("var a = new MyNativeClass(); a.test(); var b = new MyClass(); b.test();");
	}

	return 0;
}
