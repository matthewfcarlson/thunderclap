// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000bfd20 @ 0x000bfd20
#include "decls/address.h"
#include "decls/data/game/global.h"
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern unsigned int DAT_004d9968;

class __declspec(novtable) MethodBase_bfd20 {
  public:
    virtual void m0();
    char pad_04[0xc];
    char retType;
    char pad_11[7];
    char argType;
    char pad_19[3];
    MethodBase_bfd20(const char* n, int k) throw();
    void FUN_001d04a0();
};

template <class R, class A>
class Function1 : public MethodBase_bfd20 {
  public:
    typedef R (*Fn)(A);
    Function1(const char* name, Fn f) throw() : MethodBase_bfd20(name, 1) {
        fn = f;
        argType = FUN_001d04d0(((char*)&DAT_0048e100));
        retType = FUN_001d04d0(((char*)&DAT_0048e0f0));
    }
    Fn fn;
};

struct Frame_bfd20 {
    Function1<void, const char*> closure;
    unsigned int cookie;
    Frame_bfd20(const char* n, void (*f)(const char*)) throw() : closure(n, f) {
        cookie = DAT_004d9968;
    }
};

struct Registry_bfd20 {
    void FUN_001d26d0(const char*, void*);
    void FUN_000bfd20(const char* name, void (*fn)(const char*));
};

void Registry_bfd20::FUN_000bfd20(const char* name, void (*fn)(const char*)) {
    Frame_bfd20 fr(name, fn);
    FUN_001d26d0(name, &fr.closure);
    fr.closure.FUN_001d04a0();
    __security_check_cookie(fr.cookie);
}
