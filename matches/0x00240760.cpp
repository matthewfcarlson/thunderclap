// Same code shape as 0x000fc130 (propagated; names are from that function)
struct Obj {
    void f(unsigned int);
};
extern Obj* gObject;
extern "C" void __cdecl FUN_000fc130(unsigned int param_1) {
    gObject->f(param_1);
}
