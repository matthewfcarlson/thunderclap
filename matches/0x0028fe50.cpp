typedef unsigned int u32;
void __cdecl thunk_FUN_00267090(u32);
struct Obj {
    char pad[8];
    u32 field;
    void base();
    void method();
};
void Obj::method() {
    if (field) {
        thunk_FUN_00267090(field);
        field = 0;
    }
    base();
}