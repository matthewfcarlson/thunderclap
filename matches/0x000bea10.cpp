struct Obj {
    void FUN_000bea10(int, int, int, int, int, int);
};
void __cdecl FUN_000bea10(Obj* object, int* values, int unused,
                          void (Obj::*callback)(int, int, int, int, int, int)) {
    int a = *values++;
    int b = *values++;
    int c = *values++;
    int d = *values++;
    int e = *values++;
    int f = *values++;
    (object->*callback)(a, b, c, d, e, f);
}