// STATUS: equivalent (tools/equiv.py level 3: 84 inputs, branch coverage 12/12)
// hulkfight::ai::PathAction::vfunc_3 @ 0x00122370
struct Zone_122370 { char pad[0x380]; int value; };
struct ZoneRef { char pad[0x11c]; Zone_122370* zone; };
struct Node { ZoneRef* FUN_00059a30(); };
struct Owner_122370 { Node* FUN_000592a0(); };

struct Ring_122370 {
    void** head;
    void** cur;
    void** begin;
    void** limit;
};

struct Listeners {
    char pad[0x18];
    Ring_122370 ring;
};

struct Global_122370 {
    char pad[0x1c];
    Listeners* listeners;
    char pad2[0x28 - 0x20];
    int stamp;
};

struct Source_122370 {
    char pad[0x38];
    int id;
};

struct Sub_122370 {
    char pad[0x10];
    void FUN_0027b040(int id);
};

extern Global_122370* DAT_004dd700;

class PathAction {
public:
    bool run(int a, int b);
    char p0[0x1c];
    char c1c;
    char p1[3];
    int w20[6];
    float f38;
    float f3c;
    float f40;
    float f44;
    int w48;
    char p2[0x64 - 0x4c];
    int w64[4];
    int w74;
    int w78;
    int w7c;
    int w80;
    int w84;
    int w88;
    Source_122370* src8c;
    Owner_122370* owner90;
    char p3[0xb0 - 0x94];
    int wb0[6];
    ZoneRef* zoneRef;
    char p4[4];
    Sub_122370 sub;
    int stamp;
    int we4;
    char p6[4];
    int wec;
};

bool PathAction::run(int a, int b)
{
    w7c = -1;
    wec = 0;
    for (int i = 0; i < 6; i++)
        wb0[i] = 0;
    we4 = 0;
    c1c = 0;
    for (int i = 0; i < 6; i++)
        w20[i] = 0;

    zoneRef = owner90->FUN_000592a0()->FUN_00059a30();
    if (zoneRef != 0) {
        if (zoneRef->zone != 0)
            w78 = zoneRef->zone->value;
    }
    f3c = 0.2f;
    f38 = 1.0f;
    f40 = 1.0f;
    f44 = 0.3f;
    w48 = 0;
    for (int i = 0; i < 4; i++)
        w64[i] = 0;
    w74 = 2;

    Ring_122370* ring = &DAT_004dd700->listeners->ring;
    if (ring->cur < ring->limit) {
        if (ring->cur != 0)
            *ring->cur = &c1c;
        ring->cur = ring->cur + 1;
        void** limit = ring->limit;
        if (ring->cur == limit)
            ring->cur = ring->begin;
        if (ring->head == ring->cur)
            ring->cur = ring->cur + (((char*)limit - (char*)ring->begin) >> 2);
    }

    sub.FUN_0027b040(src8c->id);
    stamp = DAT_004dd700->stamp;
    w88 = 0;
    w84 = 0;
    w80 = 0;
    return true;
}
