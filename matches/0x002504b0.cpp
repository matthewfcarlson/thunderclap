struct Obj {
    void Do(int a);
};
void __cdecl FUN_002504b0(int a, int b) {
    Obj* p = (Obj*)b;
    p->Do(a);
}