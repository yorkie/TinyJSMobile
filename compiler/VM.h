#ifndef BC_VM_HH
#define BC_VM_HH

#include "Bytecode.h"
#include "Var.h"

#define VAR(i) (i->isNode ? ((BCNode*)i)->var : (BCVar*)i)
#define ERR(e) throw new CScriptException(e)

typedef struct {
	BCVar* var;
	PC pc; //stack pc
}VMScope;

class VM {
public:
	inline VM() {
		pc = 0;
		codeSize = 0;
		code = NULL;
		stackTop = STACK_DEEP;
		root = NULL;
		init();
	}

	inline ~VM() {
		reset();
	}

	inline void reset() {
		bcode.reset();
		pc = 0;
		codeSize = 0;
		code = NULL;

		while(true) {
			StackItem* i = pop2();
			if(i == NULL) 
				break;
			BCVar* v = VAR(i);
			v->unref();
		}

		if(root != NULL) {
			delete root;
			root = NULL;
		}
		
		root = NULL;
	}

	void run(const string& fname);
	
	void registerNative(const string& clsName, const string& funcDecl, JSCallback native);

private:
	PC pc;
	PC* code;
	PC codeSize;
	Bytecode bcode;

	BCVar* root;
	vector<VMScope> scopes;

	void exec();

	void init();

	const static uint16_t STACK_DEEP = 128;
	StackItem* stack[STACK_DEEP];
	uint16_t stackTop;

	void push(StackItem* v);

	StackItem* pop2();

	/**find node by name just in current scope
	@param name, name of variable;
	*/
	BCNode* find(const string& name);

	/**find node by name in all scopes
	@param name, name of variable;
	*/
	BCNode* findInScopes(const string& name);

	/**find node by name in class and superlcasses
	@param name, name of variable;
	*/
	BCNode* findInClass(BCVar* obj, const string& name);


	inline VMScope* scope() { 
		int i = scopes.size() - 1;
		return (i < 0 ? NULL : &scopes[i]);
	}

	//pop stack and release it.
	void pop();

	BCVar* funcDef(const string& funcName);

	void funcCall(const string& funcName);

	void doNew(const string& clsName);

	BCVar* getCurrentObj();

	BCVar* newObject(const string& clsName);
	
	void compare(OpCode op, BCVar* v1, BCVar* v2);
};

#endif
