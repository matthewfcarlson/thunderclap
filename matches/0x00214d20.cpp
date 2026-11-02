extern "C" void __cdecl FUN_00214c90(void *, const void *, const char *);
struct X_214d20 {
    int kind;
};
extern "C" void FUN_00214d20(void* a, void * x, const char* s) {
    void* value = ((X_214d20 *)x);
    if (((X_214d20 *)x)->kind == 4)
        value = (void*)s;
    FUN_00214c90(a, value, "concatenate");
}