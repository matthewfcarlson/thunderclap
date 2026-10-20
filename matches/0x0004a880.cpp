#include "compat/ptr.h"
extern int vftA, vftB;
class Sub_4a880 {
  public:
    void Init();
};
class C_4a880 {
  public:
    char pad[0x10];
    Sub_4a880 sub;
    void Finish();
    void Run();
};
void C_4a880::Run() {
    *(hulk_intptr*)this = (hulk_intptr)&vftA;
    sub.Init();
    *(hulk_intptr*)this = (hulk_intptr)&vftB;
    Finish();
}