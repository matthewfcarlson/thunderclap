// STATUS: equivalent (tools/equiv.py level 3: 104 inputs, branch coverage 27/28, incomplete)
// hulkfight::motion::RayCastConeCondition::vfunc_6 @ 0x00166820
struct V3 {
    float x, y, z;
    void FUN_0022d180();
    float FUN_0022d110();
};

struct Matrix {
    float m[16];
    void FUN_0022c2b0(V3* in, V3* out);
    void FUN_0022c3b0(V3* in, V3* out);
};

struct Key {
    unsigned int lo;
    unsigned int hi;
};

struct Skeleton {
    char pad00[0x1c];
    char* table;
    unsigned int FUN_002843a0(unsigned int lo, unsigned int hi);
};

struct Fighter {
    char pad00[0x120];
    Skeleton* skel;
    char pad124[0x334 - 0x124];
    void* f334;
    void* f338;
    void FUN_00035550(V3* out);
};

struct Anchor {
    Fighter* FUN_00059a30();
};

namespace fight {
class Params {
public:
    virtual void v0();
    virtual void v1();
    Anchor* FUN_000592a0();
};
}

class CFightParams : public fight::Params {
public:
    virtual void v2();
};

struct Game20 {
    char pad00[0x124];
    void* f124;
};

struct Game {
    char pad00[0x20];
    Game20* f20;
};

extern Game* DAT_004dd700;

bool FUN_002027c0(V3* from, V3* to, int a, int notSelf, V3* out1, V3* out2, int b, int c);

struct Frame {
    float v;
    V3 z0;
    V3 end;
    V3 c;
    int i;
    Fighter* fighter;
    V3 dirZ;
    V3 q18;
    V3 p;
    V3 pts[3];
    char pad78[0x90 - 0x78];
    V3 out2;
    V3 out1;
    Matrix m;
};

namespace hulkfight {
namespace motion {
class RayCastConeCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int a0, fight::Params* a1, int a2);
    char pad04[0x10 - 4];
    Key key;
    V3 axis;
    float len;
    float start;
    float step;
    unsigned char flag;
};

bool RayCastConeCondition::vfunc_6(int a0, fight::Params* a1, int a2)
{
    Frame f;
    if (dynamic_cast<CFightParams*>(a1) == 0)
        return false;
    Anchor* anchor = a1->FUN_000592a0();
    f.fighter = anchor->FUN_00059a30();
    f.fighter->FUN_00035550(&f.c);
    f.v = start;
    if (f.v > 0.0f) {
        do {
            float t = f.v * 0.017453292519943295f;
            f.pts[0].x = f.c.x + t;
            f.pts[0].y = f.z0.y + f.c.y;
            f.pts[0].z = f.z0.z + f.c.z;
            f.pts[1] = f.c;
            f.pts[2].x = f.c.x - t;
            f.pts[2].y = f.c.y - f.z0.y;
            f.pts[2].z = f.c.z - f.z0.z;
            for (int k = 0; k < 3; k++)
                f.pts[k].FUN_0022d180();
            f.i = 0;
            V3* pp = f.pts;
            do {
                Skeleton* skel = f.fighter->skel;
                if (skel != 0) {
                    unsigned int j = 0;
                    if ((key.lo | key.hi) != 0) {
                        j = skel->FUN_002843a0(key.lo, key.hi);
                        if (j == 0xffff)
                            j = 0;
                    }
                    f.p = *pp;
                    f.z0.x = 0.0f;
                    f.z0.y = 0.0f;
                    f.z0.z = 0.0f;
                    f.dirZ.x = 0.0f;
                    f.dirZ.y = 0.0f;
                    f.dirZ.z = -1.0f;
                    f.end.x = 0.0f;
                    f.end.y = 0.0f;
                    f.end.z = 0.0f;
                    f.m = *(Matrix*)(skel->table + j * 64);
                    f.q18 = axis;
                    f.m.FUN_0022c2b0(&f.q18, &f.z0);
                    f.m.FUN_0022c3b0(&f.p, &f.dirZ);
                    f.dirZ.FUN_0022d110();
                    f.end.y = f.dirZ.y * len;
                    f.end.z = f.dirZ.z * len;
                    f.end.x = f.dirZ.x * len + f.z0.x;
                    f.end.y = f.end.y + f.z0.y;
                    f.end.z = f.end.z + f.z0.z;
                    void* g = DAT_004dd700->f20->f124;
                    int notSelf = 0;
                    if (g != (void*)f.fighter && f.fighter->f338 != g && f.fighter->f334 != g)
                        notSelf = 1;
                    if (FUN_002027c0(&f.z0, &f.end, 0, notSelf, &f.out1, &f.out2, 0, 0))
                        return flag != 0;
                }
                f.v = f.v - step;
                f.i++;
                pp++;
            } while (f.i < 3);
        } while (f.v > 0.0f);
    }
    return flag == 0;
}
}
}
