// STATUS: equivalent (tools/equiv.py level 3: 79 inputs, branch coverage 21/22, incomplete)
// FUN_00318910 @ 0x00318910
extern "C" double sqrt(double);

struct Vec3 {
    float x, y, z;
};

class Probe {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec3 *v4();
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

struct Frame {
    float t;
    float tmp;
    float sq;
    int n;
    int counter;
    Vec3 d;
    Vec3 p;
    Vec3 out1;
    Vec3 out2;
};

void __cdecl FUN_002f7a90(Elem44 *e);

class Solver {
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

    char FUN_00314430(Probe *y, Vec3 *p, int ref, Vec3 *d, float *lenSq, Vec3 *out2, Vec3 *out1, int one);
    void FUN_00314be0(Probe *y, Vec3 *out2, Probe *x, Vec3 *out1, float lenSq, Vec3 *d);
    char FUN_003188d0(float lenSq);
    void FUN_00318910(Probe *a1, Probe *a2);
};

void Solver::FUN_00318910(Probe *a1, Probe *a2)
{
    Frame fr;
    fr.n = count;
    for (fr.counter = 2; fr.counter != 0; fr.counter--) {
        Probe *x = (fr.counter == 2) ? a2 : a1;
        Probe *y = (fr.counter == 2) ? a1 : a2;
        if (x->done)
            continue;

        Vec3 *q0;
        Vec3 *p0;
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
                    FUN_002f7a90(newEnd);
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
