// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002a05c0 @ 0x002a05c0
// 0x002a05c0: add a sample to the track, rebuilding keys unless it is already covered
struct Vec3_2a05c0 {
    float x, y, z;
};

class Other_2a05c0 {
public:
    char pad00[0x18];
    int field_18;
    void FUN_0029e7f0(void* a, void* b, int c);
};

class Track {
public:
    char pad00[0x18];
    int field_18;
    char pad1c[8];
    int field_24;
    char FUN_0029fca0(struct Obj_2a05c0* a, void* b, Other_2a05c0* c);
    void FUN_0029ce40(Vec3_2a05c0* out, void* b);
    void FUN_0029e320(struct Obj_2a05c0* a, Vec3_2a05c0* v, void* b);
    void FUN_0029ccb0(struct Obj_2a05c0* a, int d);
    void FUN_0029e640(struct Obj_2a05c0* a);
    void FUN_0029e680(struct Obj_2a05c0* a);
    void FUN_002a05c0(struct Obj_2a05c0* a, void* b, Other_2a05c0* c, int d);
};

struct Obj_2a05c0 {
    char pad00[0x14];
    int field_14;
};

void Track::FUN_002a05c0(Obj_2a05c0* a, void* b, Other_2a05c0* c, int d)
{
    Vec3_2a05c0 v;
    if (a->field_14 == 0)
        return;
    if (!FUN_0029fca0(a, b, c)) {
        FUN_0029ce40(&v, b);
        FUN_0029e320(a, &v, b);
        FUN_0029ccb0(a, d);
        if (c != 0) {
            c->field_18 = field_18;
            c->FUN_0029e7f0(a, b, field_24);
        }
    }
    FUN_0029e640(a);
    FUN_0029e680(a);
}
