class ControllerPollerBase {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual int vfunc_5(int);
};
class Helper_dda90 {
  public:
    int run(int, int);
};
class ControllerPoller : public ControllerPollerBase {
  public:
    int vfunc_5(int);
    char pad[0x34];
    int field;
};
extern "C" void* __cdecl FUN_0008d690(int);
int ControllerPoller::vfunc_5(int param) {
    Helper_dda90* p = (Helper_dda90*)FUN_0008d690(0x14);
    if (p)
        return p->run(field, param);
    return 0;
}