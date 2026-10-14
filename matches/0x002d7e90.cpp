typedef unsigned int uint_2d7e90;
struct Obj_2d7e90 {
    char pad[8];
    uint_2d7e90 value;
};
uint_2d7e90 target(int param_1, Obj_2d7e90* param_2, uint_2d7e90 param_3) {
    if (param_1 != 0 && param_2 != 0)
        return param_2->value & param_3;
    return 0;
}