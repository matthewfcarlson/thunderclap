// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00018570..0x000185f0 (kind game, layer game, confidence medium), dominant class CExplosionAction
#include "tree_prelude.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f766a414 {
#define TREE_TU_END }
namespace fn_f766a414 {} using namespace fn_f766a414;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f766a414 {
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

} // namespace fn_f766a414

// 0x00018570 CExplosionAction::vfunc_7 (122 B): matches/0x00018570.cpp
// sym: ?vfunc_7@CExplosionAction@@UAE_NH@Z
bool CExplosionAction::vfunc_7(int ) {
    X_18570* p = ((X_18570*)(*(struct A_18570 * *)&this->f_1c)->Get())->Next();
    Vec3_18570 v = (*(struct B_18570 * *)&this->f_20)->pos;
    Vec3_18570 out;
    p->Build(&v, &out);
    gManager_18570->f->Go(out, (*(struct B_18570 * *)&this->f_20)->val, 0, 0);
    return false;
}

