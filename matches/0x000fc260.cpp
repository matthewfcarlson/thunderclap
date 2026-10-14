// Same code shape as 0x000fc130 (propagated; names are from that function)
struct Obj_fc260 {
    void f(unsigned int);
};
extern Obj_fc260* gObject_fc260;
extern "C" void __cdecl FUN_000fc130(unsigned int param_1) {
    gObject_fc260->f(param_1);
}
