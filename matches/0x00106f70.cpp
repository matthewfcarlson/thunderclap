// Same code shape as 0x00078c40 (propagated; names are from that function)
#include "decls/data/game/global.h"
// data: gWaypoint = DAT_0040d640

class CDHGameObjectCreator {
    char a[4];
};
class DataHandler {
  public:
    class ObjectCreator {
        char b[4];
    };
};
class CPatrolPathManager : public CDHGameObjectCreator, public DataHandler::ObjectCreator {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual const char* vfunc_3(void*);
};
const char* CPatrolPathManager::vfunc_3(void*) {
    return ((char*)&DAT_0040d640);
}