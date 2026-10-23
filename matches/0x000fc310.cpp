struct S_fc310 {
    char pad[0x175c];
    int value;
};
extern S_fc310* DAT_004e0a60;
int f() {
    return DAT_004e0a60->value;
}