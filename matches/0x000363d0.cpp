struct Sub_363d0 {
    void Run();
};
struct Thing_363d0 {
    char pad[0xdc];
    Sub_363d0 sub;
    char pad2[0x1e58 - 0xdc - 4];
    int field;
    void f();
};
void Thing_363d0::f() {
    sub.Run();
    field = 0;
}