#include "decls/data/game/unknown.h"
// data: gObject_80ba0 = DAT_004e5acc

class Obj_80ba0 {
  public:
    float method(unsigned int, unsigned int);
};
extern "C" float FUN_00080ba0(unsigned int a, unsigned int b) {
    return (*(Obj_80ba0**)&DAT_004e5acc)->method(a, b);
}