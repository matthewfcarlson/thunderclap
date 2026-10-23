// STATUS: equivalent (tools/equiv.py level 3: 76 inputs, branch coverage 26/26)
// pure3d::prop::CMotionTrail::vfunc_11 @ 0x00283110
#include "gen/pure3d.h"

extern "C" double __cdecl sqrt(double);

struct Vec3_283110 {
    float x, y, z;
};

struct Skeleton_283110 {
    char pad0[0x1c];
    char *joints;
};

struct JointXform {
    void FUN_0022c2b0(Vec3_283110 *out, Vec3_283110 *in);
};

struct TrailSample {
    Vec3_283110 pos[12];
    char rest[16];
    void FUN_0027fa00(Vec3_283110 *pts);
};

struct TrailData {
    char pad0[0x1c];
    char *joints;
};

namespace pure3d {
namespace prop {
}
}
void pure3d::prop::CMotionTrail::vfunc_11(float dt, int unused) {
    struct Frame {
        Vec3_283110 d;
        float lenSq;
        Vec3_283110 pts[6];
        Vec3_283110 cross[6];
        struct { volatile unsigned x, y, z; } p;
        volatile float savedDt;
    } fr;

    if ((*(void * *)&this->f_40) == 0)
        return;
    if (this->f_7c > 0.0f && this->f_70 != 0xffff) {
        const unsigned *root = (const unsigned *)((*(TrailData * *)&this->f_44)->joints + 64 * this->f_70 + 0x30);
        fr.p.x = root[0];
        fr.p.y = root[1];
        fr.p.z = root[2];
        for (int i = 0; i < this->f_48; i++) {
            JointXform *m = (JointXform *)((*(TrailData * *)&this->f_44)->joints + 64 * (*(int * *)&this->f_74)[i]);
            m->FUN_0022c2b0((*(Vec3_283110 * *)&this->f_78) + i, &fr.pts[i]);
        }
        float maxSq = 0.0f;
        if (this->f_6c > 0) {
            TrailSample *s = (*(TrailSample * *)&this->f_64) + (this->f_68 + this->f_6c - 1) % 50;
            int n = this->f_48;
            const Vec3_283110 *cur = s->pos;
            Vec3_283110 *pt = fr.pts;
            Vec3_283110 *cr = fr.cross;
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
        if (sqrt(maxSq) > 0.01f || this->f_6c == 0) {
            if (this->f_6c < 49)
                this->f_6c++;
            else
                this->f_68 = (this->f_68 + 1) % 50;
            (*(TrailSample * *)&this->f_64)[(this->f_68 + this->f_6c - 1) % 50].FUN_0027fa00(fr.pts);
        }
    }
    this->f_7c -= dt;
}
