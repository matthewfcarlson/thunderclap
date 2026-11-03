// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002b1160 @ 0x002b1160
#include "gen/owners.h"
struct State { unsigned int values[6]; };
struct Handler {
    void FUN_002b1160(unsigned int value);
};
void Handler::FUN_002b1160(unsigned int value) {
    State state = {{0, 0, 0, 0, 0, 0}};
    ((owners::Buffer_2b1070 *)this)->FUN_002b1070((unsigned)value, (hulk_intptr)(State *)(&state));
}