struct A_1eef70 {
    void First();
};
struct B_1eef70 {
    void Second();
};
struct Obj_1eef70 {
    A_1eef70* a;
    B_1eef70* b;
    void Target();
};
void Obj_1eef70::Target() {
    a->First();
    b->Second();
}