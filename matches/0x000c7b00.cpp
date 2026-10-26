#include "decls/data/game/global.h"
// data: scale = DAT_0049fbc0

#include "compat/ptr.h"
class Provider {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int Count();
};
struct Holder {
    char pad[16];
    Provider* provider;
    int GetCount() { return provider->Count(); }
};
class Obj {
    char pad0[16];
    Holder* holder;
    char pad1[44];
    float factor;
    char pad2[460];
    float second;
    char pad3[4];
    float first;
    char pad4[10044];
    char enabled;

  public:
    void Update(float x);
};
void Obj::Update(float x) {
    enabled = 0;
    int n = holder->GetCount();
#if defined(__clang__)
    hulk_freg v = x * factor / ((float)n * DAT_0049fbc0);
    first = v;
    second = v * DAT_0049fbc0; // the original multiplies the unrounded quotient
#else
    float v = x * factor / ((float)n * DAT_0049fbc0);
    first = v;
    second = first * DAT_0049fbc0;
#endif
}