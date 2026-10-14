struct C_13ec0 {
    void second();
};
struct B_13ec0 {
    C_13ec0* first();
};
struct Obj_13ec0 {
    char pad[0x1c];
    B_13ec0* member;
    void target();
};
void Obj_13ec0::target() {
    member->first()->second();
}