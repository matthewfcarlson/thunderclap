// Same code shape as 0x002c3140 (propagated; names are from that function)
class Geometry {
  public:
    int vfunc_0();
    int vfunc_1();
    int vfunc_2();
    int vfunc_3();
    int vfunc_4();
};
class Helper_2e00f0 {
  public:
    int run(Geometry*);
};
extern void* __cdecl thunk_FUN_0008d690(unsigned int);
int Geometry::vfunc_4() {
    void* p = thunk_FUN_0008d690(0x68);
    if (p)
        return ((Helper_2e00f0*)p)->run(this);
    return 0;
}