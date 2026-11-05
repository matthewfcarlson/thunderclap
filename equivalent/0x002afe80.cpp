// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002afe80 @ 0x002afe80
#include "compat/ptr.h"
struct SubItem { bool FUN_0027af90(int key); };
struct Item { char pad[8]; SubItem sub; };
struct Collection { char pad[0x10]; Item **begin; Item **end; int FUN_002afe80(hulk_intptr key); };
int Collection::FUN_002afe80(hulk_intptr key) {
    int bytes = (int)((char*)end - (char*)begin);
    if ((bytes & ~3) <= 0) return -1;
    int i = 0;
    do {
        if (begin[i]->sub.FUN_0027af90(key)) return i;
        ++i;
    } while (i < ((int)((char*)end - (char*)begin) >> 2));
    return -1;
}