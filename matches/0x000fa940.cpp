#include "compat/ptr.h"
typedef unsigned int uint;
void* Alloc(hulk_uintptr);
uint CopyString(uint);
extern char baseVftable[];
extern char stringVftable[];
class CScriptToken {
  public:
    virtual void f0();
    virtual void f1();
    virtual CScriptToken* f2();
    uint a, b, c;
};
class CTokenString : public CScriptToken {
  public:
    virtual void g0();
    virtual void g1();
    virtual CTokenString* f2();
    uint str;
};
CTokenString* CTokenString::f2() {
    CTokenString* p = (CTokenString*)Alloc(0x14);
    CTokenString* r;
    if (p) {
        *(void**)p = (void*)&baseVftable[0];
        p->a = a;
        p->b = b;
        p->c = c;
        *(void**)p = (void*)&stringVftable[0];
        p->str = str;
        r = p;
    } else {
        r = 0;
    }
    uint v = CopyString(str);
    r->str = v;
    r->a = 0;
    return r;
}
