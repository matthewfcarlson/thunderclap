#include "gen/global.h"

struct Vec3_18570 {
    int a, b, c;
};
struct A_18570 {
    void* Get();
};
struct B_18570 {
    char pad[0x10];
    int val;
    Vec3_18570 pos;
};
struct X_18570 {
    X_18570* Next();
    void Build(Vec3_18570*, Vec3_18570*);
};
struct Final_18570 {
    void Go(Vec3_18570, int, int, int);
};
struct G_18570 {
    char pad[0x10];
    Final_18570* f;
};
extern G_18570* gManager_18570;

bool CExplosionAction::vfunc_7(int ) {
    X_18570* p = ((X_18570*)(*(struct A_18570 * *)&this->f_1c)->Get())->Next();
    Vec3_18570 v = (*(struct B_18570 * *)&this->f_20)->pos;
    Vec3_18570 out;
    p->Build(&v, &out);
    gManager_18570->f->Go(out, (*(struct B_18570 * *)&this->f_20)->val, 0, 0);
    return false;
}
