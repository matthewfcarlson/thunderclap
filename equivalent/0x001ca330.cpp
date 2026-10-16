// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001ca330 @ 0x001ca330
#include "decls/address.h"
struct Actor_1ca330 { const char* FUN_00036d00(); };
struct ActorTable_1ca330 { Actor_1ca330* FUN_00059c10(int id); };
struct World { char pad[0x44]; ActorTable_1ca330* actors; };
struct Writer_1ca330 {
    bool FUN_001d2e80();
    void FUN_001d1d50(const char* key, const char* value);
    void FUN_001d1dd0(const char* key, int value);
    void FUN_001d1e10(const char* key, int value);
    void FUN_001d1d10();
};
Writer_1ca330* FUN_001d4c90();

struct WaypointEvent {
    char pad[0x10];
    int actorId;
    char path[0x54 - 0x14];
    int waypoint;
    unsigned char firstTime;
    bool Write();
};

bool WaypointEvent::Write()
{
    Writer_1ca330* w = FUN_001d4c90();
    if (w && w->FUN_001d2e80()) {
        w->FUN_001d1d50("path", path);
        w->FUN_001d1dd0("waypoint", waypoint);
        w->FUN_001d1e10("first_time", firstTime);
        int id = actorId;
        if (DAT_004dd700) {
            Actor_1ca330* a = DAT_004dd700->actors->FUN_00059c10(id);
            const char* name = a ? a->FUN_00036d00() : "UNKNOWN";
            w->FUN_001d1d50("actor", name);
            w->FUN_001d1d10();
            return true;
        }
        w->FUN_001d1d10();
    }
    return false;
}
