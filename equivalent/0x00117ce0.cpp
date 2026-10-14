// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00117ce0 @ 0x00117ce0
extern "C" char DAT_0040ed74[];

struct RefObj {
    virtual void addRef();
    virtual void release();
};
struct Name {
    char data[8];
    void FUN_0027af00();
    void FUN_0027b040(const char *s);
};

struct MotionClosestWaypointAction {
    int vptr;
    char pad04[0x18];
    int f1c;
    RefObj *f20;
    char pad24[0xc];
    int f30;
    int f34;
    int f38;
    char pad3c[0xc];
    int f48;
    char pad4c[0xc];
    char f58;
    char pad59[3];
    int f5c;
    Name name;
    void FUN_00232660();
    MotionClosestWaypointAction *FUN_00117ce0(int a, RefObj *target);
};

MotionClosestWaypointAction *MotionClosestWaypointAction::FUN_00117ce0(int a, RefObj *target)
{
    FUN_00232660();
    vptr = (int)DAT_0040ed74;
    f1c = 0;
    f20 = 0;
    f30 = 0;
    f34 = 0x7f7fffff;
    f38 = 0x7f7fffff;
    f48 = 0;
    f58 = 0;
    f5c = 0;
    name.FUN_0027af00();
    f1c = a;
    if (target)
        target->addRef();
    if (f20)
        f20->release();
    f20 = target;
    name.FUN_0027b040("waypoint_stuck");
    return this;
}
