#include "gen/owners.h"
class Thing_245cd0 {
  public:
    char pad[0x90];
    int line;
    unsigned int index;
    unsigned int limit;
    void Step();
};
void Thing_245cd0::Step() {
    unsigned int i = index;
    if (i < limit) {
        if (((char)((owners::RingReader_245b70 *)this)->FUN_00245b70(i)) == 10)
            ++line;
        ++index;
    }
}