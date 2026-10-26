#include "decls/data/game/unknown.h"
// data: gObject_80ba0 = DAT_004e5acc

class Obj_80ba0 {
  public:
    float method(unsigned int, unsigned int);
};
extern "C" float FUN_00080ba0(unsigned int param_1, unsigned int param_2) {
    return (*(Obj_80ba0**)&DAT_004e5acc)->method(param_1, param_2);
}