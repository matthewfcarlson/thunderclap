// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 22/22)
// FUN_0007c5b0 @ 0x0007c5b0
struct V3_7c5b0 {
    float x, y, z;
};

struct Plane_7c5b0 {
    float x, y, z, d;
    void FUN_0022e1f0(V3_7c5b0 *a, V3_7c5b0 *b, float *t);
};

struct Frustum;

struct PlaneList {
    int count;
    Plane_7c5b0 p[10];
    void FUN_001c2e10(Frustum *fr);
    char FUN_001c27d0(V3_7c5b0 *pt);
    void FUN_001c27c0();
};

struct Cam_7c5b0 {
    char pad0[0xc];
    char fr[1];
};

Cam_7c5b0 **FUN_001c3d90();

struct Tracker_7c5b0 {
    char pad0[0x10];
    struct Inner {
        void FUN_00059a50(V3_7c5b0 *out);
    } *inner;
};

struct Rig_7c5b0 {
    char pad0[0x124];
    Tracker_7c5b0 *tracker;
};

struct Owner_7c5b0 {
    char pad0[0x20];
    Rig_7c5b0 *rig;
};

struct Frame_7c5b0 {
    float f10;
    float f14;
    float f18;
    float negd;     // 0x1c
    Plane_7c5b0 pl;       // 0x20
    float t;        // 0x30
    V3_7c5b0 pos;         // 0x34
    PlaneList list; // 0x40
};

class World {
public:
    char pad0[0x382c];
    Owner_7c5b0 *owner;
    bool FUN_0007c5b0(V3_7c5b0 a, V3_7c5b0 b);
};

bool World::FUN_0007c5b0(V3_7c5b0 a, V3_7c5b0 b)
{
    Frame_7c5b0 f;
    Cam_7c5b0 *cam = *FUN_001c3d90();
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
