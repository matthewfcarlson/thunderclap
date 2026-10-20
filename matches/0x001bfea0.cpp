#include "compat/ptr.h"
#include "decls/address.h"
extern "C" char hulk_at_0048e100[];
extern "C" char hulk_at_0048e134[];
class CSubtitleManager;
struct CtorV_001d0480 {
    CtorV_001d0480(void*, int);
    virtual void v_001d0480();
};
class Base : public CtorV_001d0480 {
  public:
    Base(void*);
};
Base::Base(void* p) : CtorV_001d0480(p, 1) {
}
class Closure1_1bfea0 : public Base {
  public:
    virtual void call(int);
    char pad[0x0c];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    CSubtitleManager* owner;
    Closure1_1bfea0(void*, CSubtitleManager*);
};
class Closure1 : public Closure1_1bfea0 {
  public:
    virtual void call(int);
    void* fn;
    Closure1(void*, void*, CSubtitleManager*);
};
Closure1_1bfea0::Closure1_1bfea0(void* p, CSubtitleManager* o) : Base(p) {
    owner = o;
    b = FUN_001d04d0((const char*)((hulk_intptr)hulk_at_0048e100));
    a = FUN_001d04d0((const char*)((hulk_intptr)hulk_at_0048e134));
}
Closure1::Closure1(void* p, void* f, CSubtitleManager* o) : Closure1_1bfea0(p, o) {
    fn = f;
}