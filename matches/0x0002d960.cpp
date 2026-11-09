#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

#include "compat/ptr.h"
#include "decls/data/script.h"
extern "C" char DAT_003f423c[];
struct ThisCall_001d0480 {
    void Init(const char*, int);
};
extern "C" unsigned char __cdecl Get(void*);
// Method5's initializer (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer; returns this.
class Owner_2d960 {};
typedef void (Owner_2d960::*Fn_2d960)();
class Method5 : public ScriptFunctionFields {
  public:
    virtual void Dummy();
    Fn_2d960 arg;
    Method5* Build(const char* p2, Fn_2d960 p3);
};
Method5* Method5::Build(const char* p2, Fn_2d960 p3) {
    ((ThisCall_001d0480*)(this))->Init(p2, 5);
    *(void**)this = (void*)DAT_003f423c;
    arg = p3;
    retType = Get(((char*)&DAT_0048e100));
    argTypes[0] = Get(((char*)&DAT_0048e0f0));
    argTypes[1] = Get(((char*)&DAT_0048e0f0));
    argTypes[2] = Get(((char*)&DAT_0048e128));
    argTypes[3] = Get(((char*)&DAT_0048e128));
    argTypes[4] = Get(((char*)&DAT_0048e128));
    return this;
}
