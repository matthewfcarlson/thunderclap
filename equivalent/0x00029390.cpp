// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00029390 @ 0x00029390
#include "compat/ptr.h"
struct Destination { int FUN_001035f0(int value, int flag, int extra); };
struct Intermediate { Destination* FUN_000fdc40(); };
struct Entry { char padding[0x1ca0]; Intermediate* intermediate; };
__int64 __cdecl FUN_002672f0(int value, int a, int b);
struct Owner {
    Entry* FUN_00024280(__int64 key);
    hulk_intptr FUN_00029390(int key, int value, int flag, int extra);
};
hulk_intptr Owner::FUN_00029390(int key, int value, int flag, int extra) {
    __int64 lookup = FUN_002672f0(key, 0, 0);
    Entry* entry = FUN_00024280(lookup);
    if (!entry) return 0;
    Intermediate* intermediate = entry->intermediate;
    if (!intermediate) return (hulk_intptr)entry;
    Destination* destination = intermediate->FUN_000fdc40();
    if (!destination) return 0;
    return destination->FUN_001035f0(value, flag ? 1 : 0, extra);
}
