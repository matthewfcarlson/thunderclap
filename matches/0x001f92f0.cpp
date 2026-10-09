typedef unsigned int uint;
struct Obj {
    char pad[0x10];
    bool Check(Obj*);
};
uint __cdecl FUN_001f92f0(Obj* param_1, Obj* param_2) {
    if (param_1->Check((Obj*)((char*)param_2 + 0x10)))
        return 0xffffffff;
    return ((Obj*)((char*)param_2 + 0x10))->Check(param_1) != 0;
}