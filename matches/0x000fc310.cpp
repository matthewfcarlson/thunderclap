struct S_fc310 {
    char pad[0x175c];
    int value;
};
extern S_fc310* g_fc310;
int f() {
    return g_fc310->value;
}