// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_000c0b30 @ 0x000c0b30
// cl-flags: /GS
struct Temporary {
    char data[36];
    void FUN_000c0030(int first, int second, int third);
    void FUN_001d04a0();
};
struct Owner {
    void FUN_001d26d0(int first, Temporary *value);
    void FUN_000c0b30(int first, int second, int third);
};
void Owner::FUN_000c0b30(int first, int second, int third) {
    Temporary value;
    value.FUN_000c0030(first, second, third);
    FUN_001d26d0(first, &value);
    value.FUN_001d04a0();
}
