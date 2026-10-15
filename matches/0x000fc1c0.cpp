// Same code shape as 0x000fc130 (propagated; names are from that function)
struct Obj_fc1c0 {
    void f(unsigned int);
};
extern Obj_fc1c0* gObject_fc1c0;
extern "C" void __cdecl FUN_000fc1c0(unsigned int param_1) {
    gObject_fc1c0->f(param_1);
}
