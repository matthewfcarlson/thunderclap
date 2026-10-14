// Same code shape as 0x00013ec0 (propagated; names are from that function)
struct C_15a30 {
    void second();
};
struct B_15a30 {
    C_15a30* first();
};
struct Obj_15a30 {
    char pad[0x1c];
    B_15a30* member;
    void target();
};
void Obj_15a30::target() {
    member->first()->second();
}