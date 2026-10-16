#include "gen/global.h"

class Thing_14920 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int* get();
    char pad[0x5c - 4];
    float value;
};

float CPushBackAnimationAction::vfunc_9() {
    int* p = (*(Thing_14920 * *)&this->f_1c)->get();
    if (!p)
        return 0.0f;
    return *(float*)((char*)p + 0x5c);
}
