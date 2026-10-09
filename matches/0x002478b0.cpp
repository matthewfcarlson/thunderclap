struct Obj {
    char pad[12];
    float value;
};
void __cdecl FUN_002478b0(Obj* param_1, float param_2) {
    param_1->value = param_2;
}