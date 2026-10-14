extern "C" int __cdecl FUN_0024c1c0(void*);
extern "C" void __cdecl FUN_0024c330(int, int, int, int, int);
struct S_263480 {
    char pad[4];
    int a;
    int b;
    int c;
    int d;
};
extern "C" void __cdecl FUN_00263480(int p1, S_263480* p2) {
    int x = FUN_0024c1c0(&p2->a);
    FUN_0024c330(p1, x, p2->d, p2->b, p2->c);
}