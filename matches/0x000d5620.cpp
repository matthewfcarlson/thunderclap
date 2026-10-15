// Same code shape as 0x00094490 (propagated; names are from that function)
struct Obj_d5620;
typedef void (Obj_d5620::*Fn_d5620)(int, int, int, int, int, int, int);
struct Obj_d5620 {
    int x;
};
void __cdecl FUN_000d5620(Obj_d5620* a, int* p, int b, Fn_d5620 fn) {
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
