// Same code shape as 0x001c65a0 (propagated; names are from that function)
struct Inner_2e4fb0 {
    void sub();
};
struct Obj_2e4fb0 {
    char pad[4];
    Obj_2e4fb0* target();
};
Obj_2e4fb0* Obj_2e4fb0::target() {
    ((Inner_2e4fb0*)((char*)this + 4))->sub();
    return this;
}