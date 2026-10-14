struct Sub_15aa50 {
    int x;
};
struct Obj_15aa50 {
    char pad[0x70];
    Sub_15aa50 sub;
    Sub_15aa50* FUN_0015aa50();
};
Sub_15aa50* Obj_15aa50::FUN_0015aa50() {
    return &sub;
}