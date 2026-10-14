typedef unsigned int u32_33e200;
struct Obj_33e200 {};
void __cdecl f1(Obj_33e200*, int);
void __cdecl f2(Obj_33e200*, int);
void __cdecl f3(Obj_33e200*, int);
int __cdecl f4(Obj_33e200*, int, int, int);
void __cdecl f5(Obj_33e200*, int);
void __cdecl f6(Obj_33e200*, int);
void __cdecl f7(Obj_33e200*);
void __cdecl target(Obj_33e200* p) {
    f1(p, 2);
    f2(p, 2);
    f3(p, 1);
    int x = f4(p, 0, -1, 1);
    f5(p, x == 0);
    f6(p, 1);
    f7(p);
}