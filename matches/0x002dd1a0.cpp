struct Obj {
    char pad[0x68];
    unsigned int flags;
};
void FUN_002dd1a0(Obj* param_1) {
    param_1->flags |= 1;
}