struct Obj {
    char pad[8];
    int n;
};
extern "C" int __fastcall FUN_00212bb0(Obj*, Obj*);
extern "C" int __cdecl FUN_00219430(Obj*, const char*, int);
extern "C" void __cdecl FUN_00217980(Obj*, int, int*, int);
extern "C" unsigned int __cdecl strlen(const char*);
void __cdecl FUN_00213790(Obj* o, Obj* a, const char* s) {
    int v = FUN_00212bb0(a, o);
    int pair[2];
    pair[1] = FUN_00219430(o, s, strlen(s));
    pair[0] = 4;
    FUN_00217980(o, v, pair, o->n - 8);
    o->n -= 8;
}