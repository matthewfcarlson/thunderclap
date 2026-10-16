struct Obj {
    char pad[0x1c];
    int n;
};
extern "C" int __cdecl FUN_003463c7(int, int, int, int);
int __cdecl FUN_00246750(Obj* o, int a, int b) {
    return FUN_003463c7(a, b, 1, o->n) == 1;
}