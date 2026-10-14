typedef unsigned int u32_28fe50;
void __cdecl thunk_FUN_00267090(u32_28fe50);
struct Obj_28fe50 {
    char pad[8];
    u32_28fe50 field;
    void base();
    void method();
};
void Obj_28fe50::method() {
    if (field) {
        thunk_FUN_00267090(field);
        field = 0;
    }
    base();
}