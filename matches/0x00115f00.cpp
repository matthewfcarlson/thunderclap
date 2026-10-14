class Obj_115f00 {
  public:
    void* FUN_000592a0();
    void* FUN_00059a30();
    void FUN_00036e70(void*, int);
};
class MotionClosestWaypointAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void vfunc_4();
    virtual void f5();
    char pad[0x20 - 4];
    Obj_115f00* member20;
    char pad2[0x58 - 0x24];
    unsigned char value58;
    char pad3[0x60 - 0x59];
};
void MotionClosestWaypointAction::vfunc_4() {
    if (member20) {
        void* a = member20->FUN_000592a0();
        a = ((Obj_115f00*)a)->FUN_00059a30();
        if (a) {
            *(unsigned char*)((char*)a + 0x2140) = value58;
            *((unsigned char*)a + 0x2149) = 0;
            ((Obj_115f00*)a)->FUN_00036e70((char*)this + 0x60, 0);
        }
    }
}