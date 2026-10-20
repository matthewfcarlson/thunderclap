#include "compat/ptr.h"
class Target_80e70 {
  public:
    char pad[0xec];
    int member;
    void Set(char* p);
};
void Target_80e70::Set(char* p) {
    member = (hulk_intptr)p;
    p[0xa9] = 1;
}