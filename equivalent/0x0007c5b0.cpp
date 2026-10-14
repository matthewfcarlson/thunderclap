// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 22/22)
// FUN_0007c5b0 @ 0x0007c5b0
struct V3 {
    float x, y, z;
};

struct Plane {
    float x, y, z, d;
    void FUN_0022e1f0(V3 *a, V3 *b, float *t);
};

struct Frustum;

struct PlaneList {
    int count;
    Plane p[10];
    void FUN_001c2e10(Frustum *fr);
    char FUN_001c27d0(V3 *pt);
    void FUN_001c27c0();
};

struct Cam {
    char pad0[0xc];
    char fr[1];
};

Cam **FUN_001c3d90();

struct Tracker {
    char pad0[0x10];
    struct Inner {
        void FUN_00059a50(V3 *out);
    } *inner;
};

struct Rig {
    char pad0[0x124];
    Tracker *tracker;
};

struct Owner {
    char pad0[0x20];
    Rig *rig;
};

struct Frame {
    float f10;
    float f14;
    float f18;
    float negd;     // 0x1c
    Plane pl;       // 0x20
    float t;        // 0x30
    V3 pos;         // 0x34
    PlaneList list; // 0x40
};

class World {
public:
    char pad0[0x382c];
    Owner *owner;
    bool FUN_0007c5b0(V3 a, V3 b);
};

bool World::FUN_0007c5b0(V3 a, V3 b)
{
    Frame f;
    Cam *cam = *FUN_001c3d90();
    f.list.FUN_001c2e10((Frustum *)&cam->fr);
    for (int i = 0; i < f.list.count; i++) {
        f.pl = f.list.p[i];
        f.negd = -f.pl.d;
        double s0 = a.z * f.pl.z + a.y * f.pl.y + a.x * f.pl.x;
        bool clip;
        if (!(s0 <= f.negd)) {
            double s1 = b.z * f.pl.z + b.y * f.pl.y + b.x * f.pl.x;
            if (!(s1 <= f.negd)) {
                f.list.FUN_001c27c0();
                return false;
            }
            clip = true;
        } else {
            double s1 = b.z * f.pl.z + b.y * f.pl.y + b.x * f.pl.x;
            clip = !(s1 <= f.negd);
        }
        if (clip) {
            f.pl.FUN_0022e1f0(&a, &b, &f.t);
            float cx = (b.x - a.x) * f.t + a.x;
            f.f14 = (b.y - a.y) * f.t + a.y;
            f.f18 = (b.z - a.z) * f.t + a.z;
            double sa = a.z * f.pl.z + a.y * f.pl.y + a.x * f.pl.x;
            if (!(f.negd >= sa)) {
                a.x = cx;
                a.y = f.f14;
                a.z = f.f18;
            } else {
                b.x = cx;
                b.y = f.f14;
                b.z = f.f18;
            }
        }
    }
    owner->rig->tracker->inner->FUN_00059a50(&f.pos);
    if (f.list.FUN_001c27d0(&a) == 0) {
        f.f10 = f.pos.x;
        f.f14 = f.pos.y;
        f.f18 = f.pos.z;
        double d2 = (f.f18 - a.z) * (f.f18 - a.z) + (f.f14 - a.y) * (f.f14 - a.y) + (f.f10 - a.x) * (f.f10 - a.x);
        if (d2 < 1600.0f) {
            f.list.FUN_001c27c0();
            return false;
        }
    } else {
        f.f10 = f.pos.x;
        f.f14 = f.pos.y;
        f.f18 = f.pos.z;
        double d2 = (f.f18 - a.z) * (f.f18 - a.z) + (f.f14 - a.y) * (f.f14 - a.y) + (f.f10 - a.x) * (f.f10 - a.x);
        if (d2 < 6400.0f) {
            f.list.FUN_001c27c0();
            return false;
        }
        f.f10 = f.pos.x;
        f.f14 = f.pos.y;
        f.f18 = f.pos.z;
        double d3 = (f.f18 - b.z) * (f.f18 - b.z) + (f.f14 - b.y) * (f.f14 - b.y) + (f.f10 - b.x) * (f.f10 - b.x);
        if (d3 > 10000.0f) {
            f.list.FUN_001c27c0();
            return false;
        }
    }
    f.list.FUN_001c27c0();
    return true;
}
