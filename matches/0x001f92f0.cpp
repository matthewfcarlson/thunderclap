typedef unsigned int uint_1f92f0;
struct Obj_1f92f0 {
    char pad[0x10];
    bool Check(Obj_1f92f0*);
};
uint_1f92f0 __cdecl FUN_001f92f0(Obj_1f92f0* param_1, Obj_1f92f0* param_2) {
    if (param_1->Check((Obj_1f92f0*)((char*)param_2 + 0x10)))
        return 0xffffffff;
    return ((Obj_1f92f0*)((char*)param_2 + 0x10))->Check(param_1) != 0;
}