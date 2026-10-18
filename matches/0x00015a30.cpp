// Same code shape as 0x00013ec0 (propagated; names are from that function)
struct C_15a30 {
    int second();
};
struct B_15a30 {
    C_15a30* first();
};
struct Obj_15a30 {
    char pad[0x1c];
    B_15a30* member;
    int target();
};
int Obj_15a30::target() {
    return member->first()->second();
}