// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0027fa00 @ 0x0027fa00
#include "gen/owners.h"

owners::State_27fa00* owners::State_27fa00::FUN_0027fa00(const owners::State_27fa00* source)
{
    for (int i = 0; i < 40; ++i)
        words[i] = source->words[i];
    return this;
}
