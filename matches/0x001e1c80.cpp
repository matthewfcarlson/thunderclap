#include "decls/data/script.h"
extern "C" char f(const char*);
// Function (include/decls/data/script.h): the vftable, then Function's fields.
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern char label1[];
extern char label2[];
class Root : public CtorV_001d0480 {
  public:
    Root(const char*, int);
};
Root::Root(const char* p, int n) : CtorV_001d0480(p, n) {
}
class Closure1_1e1c80 : public Root {
  public:
    virtual void a();
    Closure1_1e1c80(const char*, ScriptMemberFn);
    ScriptMemberFn val;  // 0x1c
};
Closure1_1e1c80::Closure1_1e1c80(const char* s, ScriptMemberFn p) : Root(s, 1) {
    val = p;
    retType = f(label1);
    argTypes[0] = f(label2);
}
class Closure1 : public Closure1_1e1c80 {
  public:
    virtual void a();
    Closure1(const char*, void*, ScriptMemberFn);
    void* val2;  // 0x20
};
Closure1::Closure1(const char* s, void* p, ScriptMemberFn q) : Closure1_1e1c80(s, q) {
    val2 = p;
}
