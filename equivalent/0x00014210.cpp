// STATUS: equivalent (tools/equiv.py level 3: 87 inputs, branch coverage 12/12)
// FUN_00014210 @ 0x00014210
extern "C" double cos(double);

struct Vec3 {
    float x, y, z;
    float FUN_0022d110();
};

struct Frame {
    void FUN_00035230(Vec3 *out);
    void FUN_00035550(Vec3 *out);
};

struct Probe {
    Vec3 *FUN_001c39c0();
    Vec3 *FUN_001c39d0();
};

void __cdecl FUN_00096a90(void *obj, Vec3 *out);
Probe *__cdecl FUN_001c3d90();

static float QuarterPi()
{
    return 0.78539818525f;
}

// equiv-conv: FUN_00014210 eax ecx edx esi
void FUN_00014210(int mode, Frame *frame, void *obj, Vec3 *out)
{
    if (mode == 2) {
        frame->FUN_00035550(out);
        out->y = 0.0f;
        out->FUN_0022d110();
        return;
    }

    if (mode == 1) {
        Vec3 w;
        Vec3 a;
        Vec3 b;
        a.x = 0.0f;
        a.y = 0.0f;
        a.z = 0.0f;
        frame->FUN_00035230(&a);
        b.x = 0.0f;
        b.y = 0.0f;
        b.z = 0.0f;
        FUN_00096a90(obj, &b);
        out->y = 0.0f;
        out->x = b.x - a.x;
        out->z = b.z - a.z;
        out->FUN_0022d110();

        Probe *p = FUN_001c3d90();
        if (!p)
            return;

        Vec3 *src = p->FUN_001c39c0();
        w.x = src->x;
        w.y = src->y;
        w.z = src->z;
        w.FUN_0022d110();
        w.x = w.x * 100.0f;
        w.y = w.y * 100.0f;
        w.z = w.z * 100.0f;
        Vec3 *q = p->FUN_001c39d0();
        w.x = w.x + q->x;
        w.y = w.y + q->y;
        double z = w.z + q->z;
        w.y = 0.0f;
        w.x = w.x - b.x;
        w.z = (float)(z - b.z);
        w.FUN_0022d110();

        static float ang = QuarterPi();
        static float cs = (float)cos((double)(ang * 0.5f));
        if (w.z * out->z + w.y * out->y + w.x * out->x > cs) {
            out->x = w.x;
            out->y = w.y;
            out->z = w.z;
        }
        return;
    }

    Vec3 a;
    Vec3 b;
    a.x = 0.0f;
    a.y = 0.0f;
    a.z = 0.0f;
    frame->FUN_00035230(&a);
    b.x = 0.0f;
    b.y = 0.0f;
    b.z = 0.0f;
    FUN_00096a90(obj, &b);
    out->x = b.x - a.x;
    out->z = b.z - a.z;
    out->y = 0.0f;
    out->FUN_0022d110();
}
