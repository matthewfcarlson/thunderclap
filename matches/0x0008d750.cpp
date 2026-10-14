// Same code shape as 0x0008d710 (propagated; names are from that function)
extern "C" unsigned char flag_8d750;
extern "C" void __cdecl InitA();
extern "C" void __cdecl InitC(int);
extern "C" void __cdecl DoThing(int, int);
struct Obj_8d750 {
    char pad[0x80];
    void InitB();
};
extern Obj_8d750 object_8d750;
void __cdecl Target(int a, int b) {
    if (!flag_8d750) {
        InitA();
        object_8d750.InitB();
        InitC(30);
        flag_8d750 = 1;
    }
    DoThing(b, a);
}
