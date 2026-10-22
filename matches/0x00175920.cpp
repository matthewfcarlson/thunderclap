#include "compat/ptr.h"
#include "decls/data/game/hulkfight/motion.h"

class Obj_175920 {
  public:
    virtual void V0();
    virtual void V1();
};
class Inner_175920 {
  public:
    void Init();
    void SetName(const char*);
};
class Action_175920 {
  public:
    Action_175920();
    virtual void A0();
};
class TeleportRelativeAction_175920 : public Action_175920 {
  public:
    TeleportRelativeAction_175920(int arg, Obj_175920* obj);
    virtual void A0();
    char pad04[0x18];
    int field1c;
    Obj_175920* field20;
    char pad24[4];
    Inner_175920 inner;
};
TeleportRelativeAction_175920::TeleportRelativeAction_175920(int arg, Obj_175920* obj) {
    field1c = 0;
    field20 = 0;
    inner.Init();
    field1c = arg;
    if (obj)
        obj->V0();
    if (field20)
        field20->V1();
    field20 = obj;
    inner.SetName((const char*)((hulk_intptr)((char*)&DAT_00417da4)));
}
