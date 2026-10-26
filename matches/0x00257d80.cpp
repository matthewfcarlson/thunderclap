#include "compat/ptr.h"
#include "gen/audio.h"

class Entity_257d80 {
  public:
    virtual void f0();
    virtual void f1();
};
struct Sequence_nv_257d80 {
    bool first(hulk_intptr);
    bool second(hulk_intptr);
};
extern bool __cdecl check(int, int*);

bool audio::Sequence::vfunc_5(hulk_intptr x) {
    int t;
    if (check(x, &t) && t == 1 && ((Sequence_nv_257d80*)this)->first(x) && ((Sequence_nv_257d80*)this)->second(x))
        return true;
    return false;
}
