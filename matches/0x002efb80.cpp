// Same code shape as 0x00078c40 (propagated; names are from that function)
#include "decls/data/engine/physics.h"
// data: gWaypoint = DAT_004d29a8

class SimState_2efb80 {
    char a[4];
};
class DataHandler {
  public:
    class ObjectCreator {
        char b[4];
    };
};
class ManualSimState_2efb80 : public SimState_2efb80, public DataHandler::ObjectCreator {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual const char* vfunc_3(void*);
};
const char* ManualSimState_2efb80::vfunc_3(void*) {
    return DAT_004d29a8;
}