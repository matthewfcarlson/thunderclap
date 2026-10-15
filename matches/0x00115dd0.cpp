class Obj {
  public:
    Obj* a();
    char* b();
};
class MotionStopAction {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual char vfunc_5(int, int);
    char pad[0x1c];
    Obj* obj;
};
char MotionStopAction::vfunc_5(int n, int) {
    if (n == 0) {
        if (!obj)
            return 0;
        char* p = obj->a()->b() + 0x1f58;
        *(int*)(p + 0x114) = 0;
        *(int*)(p + 0x110) = 0;
        *(int*)(p + 0x10c) = 0;
        *(int*)(p + 0x118) = 0;
    }
    return 1;
}