typedef unsigned int u32;
struct Obj {};
void __cdecl f1(Obj*, int);
void __cdecl f2(Obj*, int);
void __cdecl f3(Obj*, int);
int __cdecl f4(Obj*, int, int, int);
void __cdecl f5(Obj*, int);
void __cdecl f6(Obj*, int);
void __cdecl f7(Obj*);
void __cdecl target(Obj* p) {
    f1(p, 2);
    f2(p, 2);
    f3(p, 1);
    int x = f4(p, 0, -1, 1);
    f5(p, x == 0);
    f6(p, 1);
    f7(p);
}