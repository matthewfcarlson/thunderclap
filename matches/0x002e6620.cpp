#include "compat/ptr.h"
extern "C" char DAT_0042fd84[];
void __cdecl Release(void*) throw();
class Base_2e6620 {
  public:
    ~Base_2e6620();
};
class Language : public Base_2e6620 {
  public:
    ~Language();
    char pad[0x1c];
    void* a;
    void* b;
    void* c;
};
Language::~Language() {
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042fd84);
    Release(a);
    Release(b);
    Release(c);
}