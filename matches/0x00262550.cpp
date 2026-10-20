struct Local {
    char data[12];
    void FUN_0023fd20(int);
    void FUN_00240060();
};
struct Result {
    unsigned char FUN_00240310(int);
};
Result* __cdecl FUN_00262400(int, Local*);
unsigned char __cdecl FUN_00262550(int first, int second) {
    Local local;
    local.FUN_0023fd20(0x100);
    unsigned char value = FUN_00262400(first, &local)->FUN_00240310(second);
    local.FUN_00240060();
    return value;
}