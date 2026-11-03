#include "gen/owners.h"
void owners::A_208b40::FUN_00208b40(unsigned short x) {
    *(unsigned short*)(pad + 6 + count * 2) = x;
    ++count;
}