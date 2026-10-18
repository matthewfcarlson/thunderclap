// Same code shape as 0x000fc130 (propagated; names are from that function)
struct Obj_fc1c0 {
    int f(unsigned int);
};
extern Obj_fc1c0* gObject_fc1c0;
extern "C" int __cdecl FUN_000fc1c0(unsigned int param_1) {
    return gObject_fc1c0->f(param_1);
}
