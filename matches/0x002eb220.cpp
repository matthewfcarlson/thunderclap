typedef unsigned int uint_2eb220;
struct Thing_2eb220 {
    char pad[8];
    uint_2eb220 flags;
    char pad2[0x70];
    uint_2eb220 value;
};
void FUN_002eb220(int param_1, Thing_2eb220* param_2, uint_2eb220 param_3) {
    if (param_1 && param_2) {
        param_2->value = param_3;
        param_2->flags |= 0x40;
    }
}