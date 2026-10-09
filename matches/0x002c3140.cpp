class Geometry { public: int vfunc_0(); int vfunc_1(); int vfunc_2(); int vfunc_3(); int vfunc_4(); };
class Helper { public: int run(Geometry*); };
extern void* __cdecl thunk_FUN_0008d690(unsigned int);
int Geometry::vfunc_4() {
    void* p = thunk_FUN_0008d690(0x68);
    if (p) return ((Helper*)p)->run(this);
    return 0;
}