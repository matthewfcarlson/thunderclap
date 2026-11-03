// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0025df40 @ 0x0025df40
#include "gen/owners.h"
extern "C" void __cdecl FUN_0025dcb0(void *);


owners::Scheduler_25df40* owners::Scheduler_25df40::FUN_0025df40(hulk_intptr a, hulk_intptr b, hulk_intptr c)
{
    f04 = ((int)a);
    one = 1.0f;
    count0 = 0;
    owners::Scheduler_25df40* n0 = (owners::Scheduler_25df40*)&list0a;
    list0a = n0;
    list0b = n0;
    list0c = n0;
    list0 = n0;
    count1 = 0;
    owners::Scheduler_25df40* n1 = (owners::Scheduler_25df40*)&list1a;
    list1a = n1;
    list1b = n1;
    list1c = n1;
    list1 = n1;
    f30 = ((int)b);
    f38 = 0;
    f3c = ((int)c);
    f40 = 0;
    f44 = 0;
    f4c = 0;
    f50 = 0;
    f58 = 0;
    f34 = 0;
    b54 = (char)0xff;
    b5c = 0;
    f48 = 0;
    FUN_0025dcb0((int *)(&f40));
    f48 = 0;
    FUN_0025db30();
    return this;
}
