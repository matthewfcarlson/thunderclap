struct S {
    int a, b, c, d;
    short e, f;
};
struct T {
    int a, b, c, d, e;
};
extern "C" void __cdecl FUN_001e1040(S*, int, int, T);
extern "C" void __cdecl FUN_001e1150(S* src, S* end, S* dst, T t) {
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    dst->d = src->d;
    dst->e = src->e;
    dst->f = src->f;
    FUN_001e1040(src, 0, end - src, t);
}
