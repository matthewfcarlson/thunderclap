// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000c0b30 @ 0x000c0b30
extern unsigned int DAT_004d9968;
void __fastcall __security_check_cookie(unsigned int cookie);
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
    unsigned int cookie = DAT_004d9968;
    Temporary value;
    value.FUN_000c0030(first, second, third);
    FUN_001d26d0(first, &value);
    value.FUN_001d04a0();
    __security_check_cookie(cookie);
}
