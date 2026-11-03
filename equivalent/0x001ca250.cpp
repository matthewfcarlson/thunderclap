// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001ca250 @ 0x001ca250
#include "decls/address.h"
#include "gen/owners.h"
struct Actor_1ca250 {
    const char *FUN_00036d00();
};

struct ActorTable_1ca250 {
};

struct World {
    char pad00[0x44];
    ActorTable_1ca250 *actors;
};

struct Script_1ca250 {
    void FUN_001d1d10();
};
Script_1ca250 *FUN_001d4c90();


// Publishes the event's old/new values and the actor name to the script side.
bool owners::Event_1ca250::FUN_001ca250()
{
    Script_1ca250 *script = FUN_001d4c90();
    if (!script)
        return false;
    if (!((owners::Obj_1d2e80 *)script)->FUN_001d2e80())
        return false;
    ((owners::Obj_1d1dd0 *)script)->FUN_001d1dd0((hulk_intptr)"old", oldValue);
    ((owners::Obj_1d1dd0 *)script)->FUN_001d1dd0((hulk_intptr)"new", newValue);
    World *world = DAT_004dd700;
    int id = actorId;
    if (!world) {
        script->FUN_001d1d10();
        return false;
    }
    Actor_1ca250 *actor = ((Actor_1ca250 *)((owners::ThisWrap_00059c10 *)(world->actors))->FUN_00059c10((void *)(hulk_uintptr)(int)id));
    ((owners::Thing_1d1d50 *)script)->FUN_001d1d50((hulk_uintptr)"actor", (hulk_uintptr)(actor ? actor->FUN_00036d00() : "UNKNOWN"));
    script->FUN_001d1d10();
    return true;
}
