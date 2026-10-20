#include "compat/ptr.h"
extern "C" char DAT_0042d548[];
class Base_29b120 {
  public:
    virtual void Call();
};
class TextString {
  public:
    virtual void V();
    char pad[0x3c];
    Base_29b120* obj;
    int x44;
    int a48;
    int a4c;
    unsigned char flag;
    void Init();
    TextString* Foo(Base_29b120* p, int a, int b, unsigned char f);
};
TextString* TextString::Foo(Base_29b120* p, int a, int b, unsigned char f) {
    Init();
    *(hulk_uintptr*)this = ((hulk_intptr)DAT_0042d548);
    this->x44 = -1;
    this->obj = p;
    p->Call();
    this->a48 = a;
    this->a4c = b;
    this->flag = f;
    return this;
}
