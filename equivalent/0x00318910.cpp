// STATUS: equivalent (tools/equiv.py level 3: 5574 inputs, branch coverage 21/22, incomplete)
// FUN_00318910 @ 0x00318910
extern "C" double sqrt(double);

struct Vec3_318910 {
    float x, y, z;
};

class Probe_318910 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec3_318910 *v4();
    char pad04[0x44 - 4];
    float dirX;
    float dirY;
    float dirZ;
    float time;
    int ref;
    char done;
};

struct Elem44 {
    char pad[0x24];
    float key;
    char pad2[0x44 - 0x28];
};

struct ElemList {
    Elem44 *begin;
    Elem44 *end;
};

struct Frame_318910 {
    float t;
    float tmp;
    float sq;
    int n;
    int counter;
    Vec3_318910 d;
    Vec3_318910 p;
    Vec3_318910 out1;
    Vec3_318910 out2;
};

struct ThisCall_002f7a90 {
    void FUN_002f7a90(Elem44 *e);
};

class Solver_318910 {
public:
    char pad0[8];
    ElemList *list;
    char pad1[0x14 - 0xc];
    float dx;
    float dy;
    float dz;
    char pad2[0x2c - 0x20];
    float lenSq;
    int count;

    char FUN_00314430(Probe_318910 *y, Vec3_318910 *p, int ref, Vec3_318910 *d, float *lenSq, Vec3_318910 *out2, Vec3_318910 *out1, int one);
    void FUN_00314be0(Probe_318910 *y, Vec3_318910 *out2, Probe_318910 *x, Vec3_318910 *out1, float lenSq, Vec3_318910 *d);
    char FUN_003188d0(float lenSq);
    void FUN_00318910(Probe_318910 *a1, Probe_318910 *a2);
};

void Solver_318910::FUN_00318910(Probe_318910 *a1, Probe_318910 *a2)
{
    Frame_318910 fr;
    fr.n = count;
    for (fr.counter = 2; fr.counter != 0; fr.counter--) {
        Probe_318910 *x = (fr.counter == 2) ? a2 : a1;
        Probe_318910 *y = (fr.counter == 2) ? a1 : a2;
        if (x->done)
            continue;

        Vec3_318910 *q0;
        Vec3_318910 *p0;
        fr.t = x->time;
        p0 = x->v4();
        fr.p.x = fr.t * x->dirX + p0->x;
        fr.p.y = fr.t * x->dirY + p0->y;
        fr.p.z = fr.t * x->dirZ + p0->z;
        q0 = y->v4();
        dx = q0->x - fr.p.x;
        dy = q0->y - fr.p.y;
        dz = q0->z - fr.p.z;
        lenSq = dz * dz + dy * dy + dx * dx;
        if (FUN_00314430(y, &fr.p, x->ref, &fr.d, &lenSq, &fr.out2, &fr.out1, 1)) {
            fr.sq = fr.d.z * fr.d.z + fr.d.y * fr.d.y + fr.d.x * fr.d.x;
            if (fr.sq > 0.0f) {
                fr.tmp = fr.sq - 1.0f;
                if (fr.tmp < 0.0f)
                    fr.tmp = -fr.tmp;
                if (fr.tmp > 0.01f) {
                    double inv = 1.0 / sqrt((double)fr.sq);
                    fr.d.x = (float)(fr.d.x * inv);
                    fr.d.y = (float)(fr.d.y * inv);
                    fr.d.z = (float)(fr.d.z * inv);
                }
            }
            if (fr.n < count) {
                Elem44 *oldEnd = list->end;
                if (!(lenSq < oldEnd[-1].key))
                    continue;
                Elem44 *newEnd = list->end - 1;
                list->end = newEnd;
                if (oldEnd - 1 < newEnd)
                    ((ThisCall_002f7a90*)(this))->FUN_002f7a90(newEnd);
                count--;
            }
            FUN_00314be0(y, &fr.out2, x, &fr.out1, lenSq, &fr.d);
        } else {
            fr.sq = -x->time;
            p0 = x->v4();
            fr.p.x = fr.sq * x->dirX + p0->x;
            fr.p.y = fr.sq * x->dirY + p0->y;
            fr.p.z = fr.sq * x->dirZ + p0->z;
            q0 = y->v4();
            dx = q0->x - fr.p.x;
            dy = q0->y - fr.p.y;
            dz = q0->z - fr.p.z;
            lenSq = dz * dz + dy * dy + dx * dx;
            if (!FUN_00314430(y, &fr.p, x->ref, &fr.d, &lenSq, &fr.out2, &fr.out1, 1))
                continue;
            if (fr.n < count) {
                if (FUN_003188d0(lenSq))
                    continue;
            }
            FUN_00314be0(y, &fr.out2, x, &fr.out1, lenSq, &fr.d);
        }
    }
}
