// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000bfda0 @ 0x000bfda0
// cl-flags: /GS
#include "decls/address.h"
#include "decls/data/game/global.h"
class Base_bfda0 {
public:
    virtual void v();
    char p[12];
    char a[8];
    char result;
    char z[3];
    Base_bfda0(const char*, int) throw();
    void FUN_001d04a0();
};
template<class R>
class Function0 : public Base_bfda0 {
public:
    void* f;
    Function0(const char* n, void* x) : Base_bfda0(n, 0) {
        f = x;
        result = FUN_001d04d0(((char*)&DAT_0048e100));
    }
    virtual void v();
};
class Registry_bfda0 {
public:
    void FUN_001d26d0(const char* name, Base_bfda0* fn);
    void FUN_000bfda0(const char* name, void* fn);
};
struct Frame_bfda0 {
    Function0<void> closure;
    Frame_bfda0(const char* n, void* f) : closure(n, f) {
    }
};
void Registry_bfda0::FUN_000bfda0(const char* name, void* fn) {
    Frame_bfda0 fr(name, fn);
    FUN_001d26d0(name, &fr.closure);
    fr.closure.FUN_001d04a0();
}
