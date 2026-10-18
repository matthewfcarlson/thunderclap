struct C_13ec0 {
    int second();
};
struct B_13ec0 {
    C_13ec0* first();
};
struct Obj_13ec0 {
    char pad[0x1c];
    B_13ec0* member;
    int target();
};
int Obj_13ec0::target() {
    return member->first()->second();
}