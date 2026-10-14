// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001ca250 @ 0x001ca250
struct Actor_1ca250 {
    const char *FUN_00036d00();
};

struct ActorTable_1ca250 {
    Actor_1ca250 *FUN_00059c10(int id);
};

struct World {
    char pad00[0x44];
    ActorTable_1ca250 *actors;
};
extern World *DAT_004dd700;

struct Script_1ca250 {
    bool FUN_001d2e80();
    void FUN_001d1dd0(const char *name, int value);
    void FUN_001d1d50(const char *name, const char *value);
    void FUN_001d1d10();
};
Script_1ca250 *FUN_001d4c90();

class Event_1ca250 {
public:
    char pad00[0x10];
    int actorId;
    int oldValue;
    int newValue;
    bool FUN_001ca250();
};

// Publishes the event's old/new values and the actor name to the script side.
bool Event_1ca250::FUN_001ca250()
{
    Script_1ca250 *script = FUN_001d4c90();
    if (!script)
        return false;
    if (!script->FUN_001d2e80())
        return false;
    script->FUN_001d1dd0("old", oldValue);
    script->FUN_001d1dd0("new", newValue);
    World *world = DAT_004dd700;
    int id = actorId;
    if (!world) {
        script->FUN_001d1d10();
        return false;
    }
    Actor_1ca250 *actor = world->actors->FUN_00059c10(id);
    script->FUN_001d1d50("actor", actor ? actor->FUN_00036d00() : "UNKNOWN");
    script->FUN_001d1d10();
    return true;
}
