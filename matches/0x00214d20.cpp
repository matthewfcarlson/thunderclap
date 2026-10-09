extern void Base(void*, void*, const char*);
struct X {
    int kind;
};
void FUN_00214d20(void* a, X* x, const char* s) {
    void* value = x;
    if (x->kind == 4)
        value = (void*)s;
    Base(a, value, "concatenate");
}