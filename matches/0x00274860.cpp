#include "compat/ptr.h"
extern "C" char DAT_0042b914[];
extern "C" char DAT_0042b9bc[];
class Drive {
  public:
    virtual void A();
    virtual void B();
    char pad[0x10];
    int count;
};
class DriveSub {
  public:
    virtual void A();
    virtual void B();
};
class Obj_274860 {
  public:
    int vf;
    char pad[4];
    Drive* drive;
    void Run();
};
void Obj_274860::Run() {
    vf = ((hulk_intptr)DAT_0042b9bc);
    ((DriveSub*)((char*)drive + 4))->A();
    --drive->count;
    ((DriveSub*)((char*)drive + 4))->B();
    drive->B();
    vf = ((hulk_intptr)DAT_0042b914);
}