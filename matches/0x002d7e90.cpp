typedef unsigned int uint;
struct Obj {
    char pad[8];
    uint value;
};
uint target(int param_1, Obj* param_2, uint param_3) {
    if (param_1 != 0 && param_2 != 0)
        return param_2->value & param_3;
    return 0;
}