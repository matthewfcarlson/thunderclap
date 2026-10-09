struct Dest {
    void go();
};
struct Obj {
    char pad[0x208];
    Dest* member;
    void target();
};
void Obj::target() {
    member->go();
}