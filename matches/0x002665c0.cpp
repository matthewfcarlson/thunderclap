#include "gen/owners.h"
class Thing_2665c0 {
  public:
    void First();
    Thing_2665c0* Target(unsigned char);
};
void __cdecl Third(Thing_2665c0*);
Thing_2665c0* Thing_2665c0::Target(unsigned char flags) {
    First();
    ((owners::C_231050 *)this)->FUN_00231050();
    if (flags & 1)
        Third(this);
    return this;
}