// Same code shape as 0x000fc130 (propagated; names are from that function)
struct Obj_fc260 {
    int f(unsigned int);
};
extern Obj_fc260* gObject_fc260;
extern "C" int __cdecl FUN_000fc260(unsigned int param_1) {
    return gObject_fc260->f(param_1);
}
