typedef unsigned int uint;
struct Thing {
    char pad[8];
    uint flags;
    char pad2[0x70];
    uint value;
};
void FUN_002eb220(int param_1, Thing* param_2, uint param_3) {
    if (param_1 && param_2) {
        param_2->value = param_3;
        param_2->flags |= 0x40;
    }
}