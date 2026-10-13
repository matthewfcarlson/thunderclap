struct Sub {
    int x;
};
struct Obj {
    char pad[0x70];
    Sub sub;
    Sub* FUN_0015aa50();
};
Sub* Obj::FUN_0015aa50() {
    return &sub;
}