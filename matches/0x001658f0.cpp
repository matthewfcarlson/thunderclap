struct X {
    char FUN_001658f0(int v);
};
char X::FUN_001658f0(int v) {
    *(int*)((char*)this + 0x10) = v;
    return 1;
}