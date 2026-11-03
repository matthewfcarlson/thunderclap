// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001ca3d0 @ 0x001ca3d0
#include "gen/owners.h"
struct Arg { void FUN_0027af50(); };
owners::Packet_1ca3d0* owners::Packet_1ca3d0::FUN_001ca3d0(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int f)
{
    unsigned int* words = (unsigned int*)this;
    for (int i = 0; i < 12; ++i) words[i] = 0;
    value1c = b;
    value18 = a;
    value20 = c;
    value28 = f;
    kind = 0x30;
    subtype = 0x12;
    value24 = d;
    value10 = e;
    ((Arg*)&a)->FUN_0027af50();
    ((Arg*)&c)->FUN_0027af50();
    return this;
}