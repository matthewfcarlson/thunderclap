// Same code shape as 0x00221c40 (propagated; names are from that function)
struct Obj {
    char pad[0x40];
    struct Sub {
        void F(Obj*);
    } sub;
    char pad2[0x0c];
    int state;
    Obj* target();
};
Obj* Obj::target() {
    if (state == 1) {
        sub.F(this);
        state = 0;
    }
    return this;
}