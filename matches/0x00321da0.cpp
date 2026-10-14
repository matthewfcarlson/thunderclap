struct Dest_321da0 {
    void go();
};
struct Obj_321da0 {
    char pad[0x208];
    Dest_321da0* member;
    void target();
};
void Obj_321da0::target() {
    member->go();
}