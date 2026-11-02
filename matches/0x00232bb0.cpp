#include "decls/data/engine/fight.h"
// data: gHolder = DAT_004e5af8

class Obj {
  public:
    virtual void a();
    virtual void release();
};
struct Holder {
    Obj* obj;
    ~Holder() {
        if (obj) {
            obj->release();
            obj = 0;
        }
    }
};
extern "C" void FUN_00232bb0() {
    delete (*(Holder**)&DAT_004e5af8);
    (*(Holder**)&DAT_004e5af8) = 0;
}