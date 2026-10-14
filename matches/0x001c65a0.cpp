struct Inner_1c65a0 {
    void sub();
};
struct Obj_1c65a0 {
    char pad[4];
    Obj_1c65a0* target();
};
Obj_1c65a0* Obj_1c65a0::target() {
    ((Inner_1c65a0*)((char*)this + 4))->sub();
    return this;
}