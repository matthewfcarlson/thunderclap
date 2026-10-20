#include "compat/ptr.h"
class A_354e0 {
    char pad[16];

  public:
    int Get();
};
class Tmp_354e0 {
    char x[64];

  public:
    void Init();
    void SetArg(int);
    void SetPtr(int);
};
class Obj_354e0 {
    char pad[16];

  public:
    bool target(int);
    bool Run(Tmp_354e0*);
};
bool Obj_354e0::target(int arg) {
    int p = ((A_354e0*)*(hulk_intptr*)((char*)this + 0x10))->Get();
    if (!p)
        return false;
    Tmp_354e0 t;
    t.Init();
    t.SetArg(arg);
    t.SetPtr(p + 0x40);
    return Run(&t);
}
