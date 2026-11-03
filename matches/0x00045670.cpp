#include "decls/data/game/global.h"
#include "gen/owners.h"

class C2_45670 {
  public:
    int Get();
};
class C1_45670 {
  public:
};
class Mgr_45670 {
  public:
    char pad[0x54];
    C1_45670* m54;
};
extern Mgr_45670* gMgr_45670;
float owners::Obj_45670::FUN_00045670() {
    float r = DAT_003f32dc;
    Mgr_45670* m = gMgr_45670;
    if (m && m->m54) {
        C2_45670* s = ((C2_45670 *)((owners::C_86310 *)(m->m54))->FUN_00086310());
        if (s) {
            int k = ((C2_45670 *)((owners::C_86310 *)(m->m54))->FUN_00086310())->Get();
            switch (k) {
            case 0:
                r = f314;
                break;
            case 1:
                r = f318;
                break;
            case 2:
                r = f31c;
                break;
            default:
                r = f318;
                break;
            }
        }
    }
    return r;
}
