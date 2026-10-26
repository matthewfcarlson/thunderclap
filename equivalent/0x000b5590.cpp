// STATUS: equivalent (tools/equiv.py level 3: 19973 inputs, branch coverage 9/9)
// FUN_000b5590 @ 0x000b5590
// FUN_000b5590 @ 0x000b5590: set the colour and text of the side-mission success ranking.
// The extent is 0xb5590..0xb566f: the switch arms at 0xb55e0/5600/5620/5640 are part of this function.
#include "decls/data/game/global.h"

struct Ranking { void FUN_000f8500(const float*, int, int); };
struct Object {
    virtual void FUN_00000000(); virtual void FUN_00000001(); virtual void FUN_00000002(); virtual void FUN_00000003();
    char pad[0x14];
    Ranking ranking;                // 0x18
    char pad2[0x3c - 0x18 - 1];
    int color;                      // 0x3c
};
extern "C" Object* __cdecl FUN_000fc260(const char*);

void __stdcall FUN_000b5590(unsigned int value)
{
    Object* object = FUN_000fc260("side_mission_success_ranking");
    if (!object)
        return;
    const char* text;
    switch (value) {
    case 0:
        object->ranking.FUN_000f8500(((float*)&DAT_003f335c), 0, 1);
        object->FUN_00000003();
        return;
    case 1:  object->color = 0xffc8821e; text = "TBS_SIDE_MISSION_TEXT_8"; break;
    case 2:  object->color = 0xffb4c5c4; text = "TBS_SIDE_MISSION_TEXT_9"; break;
    case 3:  object->color = 0xffe6e11e; text = "TBS_SIDE_MISSION_TEXT_10"; break;
    default: object->color = 0xffffffff; text = "UNKNOWN"; break;
    }
    object->ranking.FUN_000f8500((const float*)text, 0, 1);
    object->FUN_00000003();
}
