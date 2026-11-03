// eq64 mutant of matches/0x000ac780.cpp: a pointer kept in an int field (truncated on 64-bit)
#include "compat/ptr.h"
class Target_ac780 {
    char pad[0x14];

  public:
    int value;
    char pad2[4];
    unsigned char flag;
    void Set(int x);
};
void Target_ac780::Set(int x) {
    value = (int)(hulk_intptr)this;
    flag = 1;
}
