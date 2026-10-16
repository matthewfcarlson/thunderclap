// STATUS: equivalent (tools/equiv.py level 3: 77 inputs, branch coverage 30/30)
// FUN_00081420 @ 0x00081420
#include "decls/address.h"
extern "C" double sqrt(double);
struct Vec3_81420 {
    float x, y, z;
    float FUN_0022d110();
};

struct Matrix {
    char pad[0x40];
    void FUN_0022ba70(float angle);
};

struct Clock_81420 {
    float FUN_000787e0(float lo, float hi);
};

struct RefObj_81420 {
    char pad00[8];
    RefObj_81420* next;       // 0x08
    int kind;           // 0x0c
};

struct Linked_81420 {
    void FUN_0003ee70(int handle);
};

struct Stats_81420 {
    char pad00[0x10];
    int* handlePtr;     // 0x10
    bool FUN_00035ab0();
};

struct Request {
    char pad00[8];
    Stats_81420* stats;       // 0x08
    int kind;           // 0x0c
};

struct Controller_81420 {
    void FUN_001ec980(Stats_81420* stats, const char* name);
};

struct World {
    char pad00[0x34];
    Controller_81420* controller;
};

struct Source_81420 {
    char b14pad[0x14];
    char flag14;        // 0x14
    char pad15[0x28 - 0x15];
    Vec3_81420 vel;           // 0x28
    char flag34;        // 0x34
    char pad35[0x4c - 0x35];
    Request* req;       // 0x4c
    char pad50[0x64 - 0x50];
    int f64;
    char pad68[0x78 - 0x68];
    float f78;
    char pad7c[0x84 - 0x7c];
    RefObj_81420* f84;
    int f88;
    float f8c;
    char flag90;        // 0x90
};

class Fx_81420 {
public:
    void FUN_00081420(Source_81420* src);

    char pad00[0x10];
    int state;          // 0x10
    char pad14[0x20 - 0x14];
    int f20;
    int f24;
    unsigned int flags; // 0x28
    char pad2c[0x34 - 0x2c];
    Matrix m34;
    char pad74[0x8c - 0x74];
    float f8c;
    float f90;
    float f94;
    int f98;
    int f9c;
    int fa0;
    Vec3_81420 fa4;
    float fb0;
    float fb4;
    RefObj_81420* fb8;
    char padbc[0x100 - 0xbc];
    int f100;
};

extern Clock_81420* DAT_004e5acc;

float FUN_00224f10(Vec3_81420* v);
int FUN_000113e0(int lo, int hi);
void FUN_00018810(RefObj_81420** slot, RefObj_81420* obj);

void Fx_81420::FUN_00081420(Source_81420* src)
{
    if (state == 5 || state == 6)
        return;
    if ((flags >> 7) & 1)
        return;

    float angle = 0.0f;
    state = 7;
    flags |= 3;
    f8c = FUN_00224f10(&src->vel);
    f98 = src->f64;
    if (src->flag90) {
        f94 = DAT_004e5acc->FUN_000787e0(8.0f, 10.0f);
        f90 = DAT_004e5acc->FUN_000787e0(15.0f, 27.0f);
    } else if (src->flag14) {
        f94 = DAT_004e5acc->FUN_000787e0(10.0f, 20.0f);
        f90 = DAT_004e5acc->FUN_000787e0(8.0f, 10.0f);
    } else {
        f94 = (float)sqrt(src->vel.x * src->vel.x + src->vel.z * src->vel.z);
        *(int*)&f90 = *(int*)&src->vel.y;
    }

    if (f94 * 3.0f < f90) {
        f9c = 3;
        angle = 3.14159274f;
    } else if (f94 > f90) {
        f9c = 2;
        angle = 3.14159274f;
    } else {
        f9c = FUN_000113e0(0, 1);
    }

    m34.FUN_0022ba70(angle + f8c);
    f20 -= (int)src->f78;

    if (src->f84) {
        fa0 = src->f88;
        fa4 = src->vel;
        fb0 = fa4.FUN_0022d110();
        fb4 = src->f8c;
        FUN_00018810(&fb8, src->f84);
        RefObj_81420* r = fb8;
        if (r && r->kind == 1) {
            Linked_81420* l = (Linked_81420*)r->next;
            if (l)
                l->FUN_0003ee70(f100);
        }
        f8c = angle;
    }

    Request* req = src->req;
    if (req && req->kind == 1) {
        Stats_81420* stats = req->stats;
        f24 = *stats->handlePtr;
        if (stats->FUN_00035ab0() && !src->flag34)
            DAT_004dd700->controller->FUN_001ec980(stats, "punch_sml");
    }
}
