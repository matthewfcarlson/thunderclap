// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001ca170 @ 0x001ca170
#include "decls/address.h"
struct Actor_1ca170 { const char* FUN_00036d00(); };
struct ActorTable_1ca170 { Actor_1ca170* FUN_00059c10(int id); };
struct World { char pad[0x44]; ActorTable_1ca170* actors; };
struct Writer_1ca170 {
    bool FUN_001d2e80();
    void FUN_001d1d90(const char* key, int value);
    void FUN_001d1d50(const char* key, const char* value);
    void FUN_001d1d10();
};
Writer_1ca170* FUN_001d4c90();

struct PositionEvent {
    char pad[0x10];
    int actorId;
    char pad14[0x54 - 0x14];
    int x, y, z;
    bool Write();
};

bool PositionEvent::Write()
{
    Writer_1ca170* w = FUN_001d4c90();
    if (w && w->FUN_001d2e80()) {
        w->FUN_001d1d90("x", x);
        w->FUN_001d1d90("y", y);
        w->FUN_001d1d90("z", z);
        int id = actorId;
        if (DAT_004dd700) {
            Actor_1ca170* a = DAT_004dd700->actors->FUN_00059c10(id);
            const char* name = a ? a->FUN_00036d00() : "UNKNOWN";
            w->FUN_001d1d50("actor", name);
            w->FUN_001d1d10();
            return true;
        }
        w->FUN_001d1d10();
    }
    return false;
}
