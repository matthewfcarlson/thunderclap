class JointDriver {
  public:
    int vfunc_0();
    int vfunc_1();
    int vfunc_2();
    int vfunc_3();
    int vfunc_4();
    int vfunc_5();
};
class Helper {
  public:
    int run(JointDriver*);
};
extern void* thunk_FUN_0008d690(int);
int JointDriver::vfunc_5() {
    Helper* p = (Helper*)thunk_FUN_0008d690(0x70);
    if (p)
        return p->run(this);
    return 0;
}