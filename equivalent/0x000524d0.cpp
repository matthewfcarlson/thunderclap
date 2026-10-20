// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 9/10, incomplete)
// CGrappleFightNodeTimeCondition::vfunc_7 @ 0x000524d0
#include "gen/global.h"

struct Result { char pad[0xdc]; };
struct Node_524d0 { char pad[0x330]; Result* first; Result* second; Result* third; };
struct Intermediate { Node_524d0* FUN_00059a30(); };
struct Input { Intermediate* FUN_000592a0(); };

int CGrappleFightNodeTimeCondition::vfunc_7(void* __p0) { Input * input = (Input *)__p0;

    if (!input) return (int)(0);
    Node_524d0* node = input->FUN_000592a0()->FUN_00059a30();
    Result* result = node->second;
    if (!result) result = node->first;
    if (!result) result = node->third;
    if (!result) return (int)(0);
    return (int)((Result*)((char*)result + 0xdc));
}
