// STATUS: equivalent (tools/equiv.py level 3: 77 inputs, branch coverage 23/24, incomplete)
// FUN_00084610 @ 0x00084610
struct Vec3 {
    float x, y, z;
    void FUN_0022d180();
};

struct Hit {
    char pad00[8];
    Vec3 *pos;
};

struct Tracker {
    bool FUN_001dd800(int handle);
    void FUN_001dd840(int handle, int flag);
};

struct Level {
    bool FUN_002ee140(Hit *hit, Vec3 *from, Vec3 *to, int flags);
};

struct Cursor {
    int FUN_000797b0(int a, int b);
    bool FUN_0007c930(Vec3 v, int c);
};

struct Systems {
    char pad00[0x0c];
    Tracker *tracker;       // 0x0c
    struct {
        char pad00[8];
        Level *level;       // 0x08
    } *world;               // 0x10
    char pad14[0x4c - 0x14];
    Cursor *cursor;         // 0x4c
};

extern Systems *DAT_004dd700;
extern int DAT_004d2a3c;
extern char DAT_004d2a40;
extern char DAT_00554c1c;
extern float DAT_00554c18;

Hit *FUN_00202f00();

class Pointer {
public:
    char pad00[8];
    int f08;
    int f0c;
    int mode;           // 0x10
    char pad14[4];
    float value;        // 0x18
    float limit;        // 0x1c
    char pad20[0x34 - 0x20];
    int handle;         // 0x34
    char pad38[0x60 - 0x38];
    Vec3 pos;           // 0x60
    Vec3 dir;           // 0x6c

    void FUN_00084610(float dt);
};

void Pointer::FUN_00084610(float dt)
{
    struct Frame {
        Vec3 hit;
        Vec3 to;
        Vec3 from;
    } fr;

    if (DAT_004dd700->tracker->FUN_001dd800(handle)) {
        DAT_004dd700->tracker->FUN_001dd840(handle, 0);
        Hit *h = FUN_00202f00();
        DAT_004d2a3c = 2;
        DAT_004d2a40 = 0;
        DAT_00554c1c = 1;
        DAT_00554c18 = 0.35f;
        dir.FUN_0022d180();
        fr.hit.z = dir.z * 15.0f;
        fr.from.x = pos.x;
        fr.from.z = pos.z;
        fr.from.y = pos.y;
        fr.to.x = dir.x * 15.0f + pos.x;
        fr.to.y = dir.y * 15.0f + pos.y;
        fr.to.z = fr.hit.z + pos.z;
        if (DAT_004dd700->world->level->FUN_002ee140(h, &fr.from, &fr.to, 0)) {
            fr.hit.x = h->pos->x;
            fr.hit.y = h->pos->y;
            fr.hit.z = h->pos->z;
            if (fr.hit.x > 10.0f)
                value = value - dt * 5.0f;
            else if (fr.hit.x > 5.0f)
                value = value - dt * 10.0f;
            else
                value = 0;
        } else {
            if (mode != 1 && mode != 2)
                value = dt * 5.0f + value;
        }
        if (!(value >= 0.0f && value <= limit)) {
            if (value > limit)
                value = limit;
            else
                value = 0.0f;
        }
        DAT_004dd700->tracker->FUN_001dd840(handle, 1);
    } else {
        Cursor *c = DAT_004dd700->cursor;
        int r = c->FUN_000797b0(f08, f0c);
        if (c->FUN_0007c930(pos, r)) {
            value = 0;
            return;
        }
        if (mode != 1 && mode != 2)
            value = limit;
    }
}
