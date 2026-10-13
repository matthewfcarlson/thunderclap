extern "C" void __stdcall FUN_002580e0(void*);
extern int gObj;
struct Obj {
    void Fn();
};
extern "C" void __stdcall FUN_003643b0() {
    ((Obj*)&gObj)->Fn();
}
