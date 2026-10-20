struct Triple {
    unsigned int x, y, z;
};
void __cdecl FUN_00095fa0(Triple* value, unsigned int arg);
Triple* __stdcall FUN_00025420(Triple* result, unsigned int x, unsigned int y, unsigned int z,
                               unsigned int arg) {
    Triple value;
    value.x = x;
    value.y = y;
    value.z = z;
    FUN_00095fa0(&value, arg);
    *result = value;
    return result;
}