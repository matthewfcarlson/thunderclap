struct Obj {
    char pad[28];
    int data;
    bool(__cdecl* fn)(int, int, int);
};
bool __cdecl FUN_00246c60(Obj* p, int a, int b) {
    p->fn(p->data, a, b);
    return true;
}