struct C {
    void second();
};
struct B {
    C* first();
};
struct Obj {
    char pad[0x1c];
    B* member;
    void target();
};
void Obj::target() {
    member->first()->second();
}