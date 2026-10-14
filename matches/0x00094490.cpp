struct Obj_94490;
typedef void (Obj_94490::*Fn_94490)(int, int, int, int, int, int, int);
struct Obj_94490 {
    int x;
};
void __cdecl FUN_00094490(Obj_94490* a, int* p, int b, Fn_94490 fn) {
    int* q = p;
    int v0 = *q;
    q++;
    int v1 = *q;
    q++;
    int v2 = *q;
    q++;
    int v3 = *q;
    q++;
    int v4 = *q;
    q++;
    int v5 = *q;
    q++;
    int v6 = *q;
    (a->*fn)(v0, v1, v2, v3, v4, v5, v6);
}
