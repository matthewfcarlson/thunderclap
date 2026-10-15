extern "C" int FUN_00344e74(void* p, int a, void* b, void* c, int d);
class Obj {
  public:
    virtual bool vfunc_0(void* p);
};
bool Obj::vfunc_0(void* p) {
    return (int)FUN_00344e74(p, 0, (void*)0x491ca8, (void*)0x493de0, 0) != 0;
}
