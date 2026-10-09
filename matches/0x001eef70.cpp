struct A {
    void First();
};
struct B {
    void Second();
};
struct Obj {
    A* a;
    B* b;
    void Target();
};
void Obj::Target() {
    a->First();
    b->Second();
}