// Same code shape as 0x00078c40 (propagated; names are from that function)
#include "decls/data/engine/physics.h"
// data: gWaypoint = DAT_004d29a8

class CDHGameObjectCreator {
    char a[4];
};
class DataHandler {
  public:
    class ObjectCreator {
        char b[4];
    };
};
class CAmbientsManager : public CDHGameObjectCreator, public DataHandler::ObjectCreator {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual const char* vfunc_3(void*);
};
const char* CAmbientsManager::vfunc_3(void*) {
    return DAT_004d29a8;
}