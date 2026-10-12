// STATUS: equivalent (tools/equiv.py level 3: 76 inputs, branch coverage 26/26)
// pure3d::prop::CMotionTrail::vfunc_11 @ 0x00283110
extern "C" double __cdecl sqrt(double);

struct Vec3 {
    float x, y, z;
};

struct Skeleton {
    char pad0[0x1c];
    char *joints;
};

struct JointXform {
    void FUN_0022c2b0(Vec3 *out, Vec3 *in);
};

struct TrailSample {
    Vec3 pos[12];
    char rest[16];
    void FUN_0027fa00(Vec3 *pts);
};

struct TrailData {
    char pad0[0x1c];
    char *joints;
};

namespace pure3d {
namespace prop {
class CMotionTrail {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11(float dt, int unused);
    virtual void vfunc_12();
    virtual void vfunc_13();

    char pad04[0x40 - 4];
    void *active;
    TrailData *skel;
    int pointCount;
    char pad4c[0x64 - 0x4c];
    TrailSample *ring;
    int head;
    int length;
    int joint;
    int *jointIndex;
    Vec3 *outPos;
    float timer;
};
}
}

void pure3d::prop::CMotionTrail::vfunc_11(float dt, int unused)
{
    struct Frame {
        Vec3 d;
        float lenSq;
        Vec3 pts[6];
        Vec3 cross[6];
        struct { volatile unsigned x, y, z; } p;
        volatile float savedDt;
    } fr;

    if (active == 0)
        return;
    if (timer > 0.0f && joint != 0xffff) {
        const unsigned *root = (const unsigned *)(skel->joints + 64 * joint + 0x30);
        fr.p.x = root[0];
        fr.p.y = root[1];
        fr.p.z = root[2];
        for (int i = 0; i < pointCount; i++) {
            JointXform *m = (JointXform *)(skel->joints + 64 * jointIndex[i]);
            m->FUN_0022c2b0(outPos + i, &fr.pts[i]);
        }
        float maxSq = 0.0f;
        if (length > 0) {
            TrailSample *s = ring + (head + length - 1) % 50;
            int n = pointCount;
            const Vec3 *cur = s->pos;
            Vec3 *pt = fr.pts;
            Vec3 *cr = fr.cross;
            for (int i = 0; i < n; i++) {
                fr.d.x = cur->x - pt->x;
                fr.d.y = cur->y - pt->y;
                fr.d.z = cur->z - pt->z;
                fr.lenSq = fr.d.z * fr.d.z + fr.d.y * fr.d.y + fr.d.x * fr.d.x;
                if (maxSq < fr.lenSq)
                    maxSq = fr.lenSq;
                if (i > 1) {
                    float wx = cur[-1].x - pt->x;
                    float wy = cur[-1].y - pt->y;
                    float wz = cur[-1].z - pt->z;
                    cr->x = fr.d.y * wz - wy * fr.d.z;
                    cr->y = fr.d.z * wx - wz * fr.d.x;
                    cr->z = wy * fr.d.x - fr.d.y * wx;
                }
                cur++;
                pt++;
                cr++;
            }
        }
        fr.savedDt = dt;
        if (sqrt(maxSq) > 0.01f || length == 0) {
            if (length < 49)
                length++;
            else
                head = (head + 1) % 50;
            ring[(head + length - 1) % 50].FUN_0027fa00(fr.pts);
        }
    }
    timer -= dt;
}
