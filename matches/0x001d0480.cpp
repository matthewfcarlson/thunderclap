// Function's constructor (include/decls/data/script.h ScriptFunctionFields): the name and the argument count.
#include "decls/data/script.h"
class Function : public ScriptFunctionFields {
  public:
    virtual void f();
    Function(const char* n, int count);
};
Function::Function(const char* n, int count) {
    name = n;
    argc = count;
    key = 0;
}
