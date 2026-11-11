// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00172910..0x00172c00 (kind game, layer game, confidence medium), dominant class hulkfight::motion::SnapToGroundAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb8c937a {
#define TREE_TU_END }
namespace fn_fb8c937a {} using namespace fn_fb8c937a;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace hulkfight { namespace motion {
class Q_172910 {
  public:
    void* f1();
};
} }
namespace hulkfight { namespace motion {
class R_172910 {
  public:
    void* f2();
};
} }
namespace hulkfight { namespace motion {
class S_172910 {
  public:
    void* f3(int);
};
} }
namespace fn_fb8c937a {
struct Vec_172950 { float x,y,z; };
struct Actor_172950;
struct Entity_172950 { Actor_172950* FUN_00059a30(); void FUN_00059a50(Vec_172950*); };
struct Handle_172950 {  };
struct Actor_172950 {
 char pad[0x1a39];
 unsigned char grounded;
 char pad2[2];
 Vec_172950 fallback;
 char pad3[0x18];
 Vec_172950 ground;
 void FUN_00035250(Vec_172950*);
 bool FUN_00038660(Vec_172950*, float, Vec_172950*, Vec_172950*, int, int, int, int, int);
};

} // namespace fn_fb8c937a

// 0x00172910 hulkfight::motion::VisibilityAction::vfunc_3 (57 B): matches/0x00172910.cpp
// sym: ?vfunc_3@VisibilityAction@motion@hulkfight@@UAE_NHH@Z
 // namespace hulkfight
bool hulkfight::motion::VisibilityAction::vfunc_3(hulk_intptr , hulk_intptr ) {
    if ((*(void * *)&this->f_20)) {
        void* x = ((Q_172910*)(*(void * *)&this->f_20))->f1();
        if (x) {
            void* y = ((R_172910*)x)->f2();
            if (y) {
                void* z = ((S_172910*)y)->f3(1);
                *(unsigned char*)((char*)z + 0xa8) = *(((unsigned char*)(*(void * *)&this->f_1c)) + 0x10);
            }
        }
    }
    return false;
}


// 0x00172950 hulkfight::motion::SnapToGroundAction::vfunc_3 (219 B): equivalent/0x00172950.cpp
// sym: ?vfunc_3@SnapToGroundAction@motion@hulkfight@@UAE_NHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// hulkfight::motion::SnapToGroundAction::vfunc_3 @ 0x00172950
bool hulkfight::motion::SnapToGroundAction::vfunc_3(hulk_intptr , hulk_intptr ) {
 if((*(Handle_172950 * *)&this->f_20)) {
 Entity_172950* entity=((Entity_172950 *)((owners::Object_592a0 *)((*(Handle_172950 * *)&this->f_20)))->FUN_000592a0());
 if(entity) {
 Actor_172950* actor=entity->FUN_00059a30();
 if(actor) {
 if(actor->grounded) { actor->FUN_00035250(&actor->ground); return false; }
 Vec_172950 start; start.x=0;start.y=0;start.z=0;
 entity->FUN_00059a50(&start);
 start.y += 10.0f;
 Vec_172950 result, normal;
 if(actor->FUN_00038660(&start,10000.0f,&result,&normal,0,0,-1,0,0)) actor->FUN_00035250(&result);
 else actor->FUN_00035250(&actor->fallback);
 }
 }
 }
 return false;
}

