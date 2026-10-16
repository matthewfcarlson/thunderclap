// STATUS: equivalent (tools/equiv.py level 3: 3021 inputs, branch coverage 38/40, incomplete)
// FUN_00081690 @ 0x00081690
#include "decls/address.h"
struct V3_81690 {
    float x, y, z;
    void FUN_00023750(const V3_81690* other);
    void FUN_00011160(float scale, const V3_81690* dir);
};

union FloatBits_81690 {
    float f;
    unsigned int u;
};

struct Matrix {
    float m[12];
    V3_81690 pos;
    float w;
    void FUN_0022ba70(float angle);
    void FUN_0022cc90(const V3_81690* dir);
};

struct Anchor_81690 {
    void FUN_00059a50(V3_81690* out);
};

struct Node124_81690 {
    char pad00[0x10];
    Anchor_81690* anchor;
};

struct Game20_81690 {
    char pad00[0x124];
    Node124_81690* f124;
};

struct World {
    char pad00[0x20];
    Game20_81690* f20;
};


float __cdecl FUN_00224f10(V3_81690* dir);

class Body_81690 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(Matrix* m, int zero);
};

struct Sink_81690 {
    void FUN_001c4d60(Matrix* m);
};

struct Slot_81690 {
    char pad00[0x1c];
    Matrix* mat;
};

class Registry_81690 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual Slot_81690* v11();
};

struct Frame_81690 {
    V3_81690 w;
    V3_81690 pos;
    V3_81690 nd;
};

class Entity {
public:
    char pad00[0x10];
    unsigned int state;
    char pad14[0x20 - 0x14];
    int f20;
    char pad24[4];
    unsigned int flags;
    float f2c;
    char pad30[4];
    Matrix m34;
    char pad74[0x84 - 0x74];
    int f84;
    int f88;
    float f8c;
    float f90;
    float f94;
    float f98;
    int f9c;
    char pada0[0xdc - 0xa0];
    V3_81690 fdc;
    Registry_81690* fe8;
    Sink_81690* fec;
    char padf0[0x100 - 0xf0];
    Body_81690* f100;
    void FUN_00081690(int a0, V3_81690* dir, float step, bool lock, int a4);
};

void Entity::FUN_00081690(int a0, V3_81690* dir, float step, bool lock, int a4)
{
    Frame_81690 f;
    FloatBits_81690 fb;
    fb.f = dir->y;
    fb.u &= 0x7fffffff;
    fb.f = fb.f - 1.0f;
    fb.u &= 0x7fffffff;
    bool nearY = fb.f <= 0.2f;
    bool move = true;
    if (nearY)
        f84 = 0;
    unsigned int fl = flags;
    if ((fl >> 7) & 1)
        return;
    if (!lock) {
        switch (state) {
        case 1:
            if (!nearY) {
                state = 0xe;
                flags = fl | 2;
            }
            break;
        case 2:
        case 3:
            if (!nearY) {
                Anchor_81690* anchor = DAT_004dd700->f20->f124->anchor;
                f.w.y = 0.0f;
                anchor->FUN_00059a50(&f.pos);
                f.pos.FUN_00023750(&m34.pos);
                if (f.pos.z * dir->x - f.pos.x * dir->z > 0.0f) {
                    f.w.x = dir->z;
                    f.w.z = -dir->x;
                } else {
                    f.w.z = dir->x;
                    f.w.x = -dir->z;
                }
                fdc = m34.pos;
                fdc.FUN_00011160(100.0f, &f.w);
            }
            break;
        case 5:
        case 6:
            move = false;
            break;
        case 7:
        case 8:
            if (state == 8) {
                if (f2c >= 1.0f)
                    f20 = 0;
            }
            if (nearY) {
                if (f90 < 0.0f) {
                    if (f94 > 5.0f) {
                        m34.FUN_0022ba70(f8c + 3.1415927f);
                        flags = flags | 2;
                        state = 0xb;
                    } else if (f94 > 3.0f) {
                        m34.FUN_0022ba70(f8c + 3.1415927f);
                        flags = flags | 2;
                        state = 0xf;
                    } else {
                        state = 0xa;
                        flags = fl | 3;
                    }
                }
            } else {
                f.nd.x = -dir->x;
                f.nd.y = -dir->y;
                f.nd.z = -dir->z;
                m34.FUN_0022cc90(&f.nd);
                flags = flags | 3;
                state = 9;
            }
            break;
        default:
            break;
        }
    } else {
        if (state <= 0xf) {
            if (state == 5 || state == 6) {
                move = false;
            } else {
                flags = fl | 1;
                f94 = 4.0f;
                f90 = 4.0f;
                f8c = FUN_00224f10(dir);
                f88 = 0;
                f9c = 0;
                flags = flags | 2;
                f98 = 30.0f;
                state = 7;
            }
            f20 = f20 - 1;
        } else {
            f20 = f20 - 1;
        }
    }
    if (move) {
        m34.pos.x = step * dir->x + m34.pos.x;
        m34.pos.y = step * dir->y + m34.pos.y;
        m34.pos.z = step * dir->z + m34.pos.z;
    }
    f100->v6(&m34, 0);
    fec->FUN_001c4d60(&m34);
    *fe8->v11()->mat = m34;
}
