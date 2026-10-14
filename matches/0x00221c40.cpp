struct Obj_221c40 {
    char pad[0x40];
    struct Sub {
        void F(Obj_221c40*);
    } sub;
    char pad2[0x0c];
    int state;
    Obj_221c40* target();
};
Obj_221c40* Obj_221c40::target() {
    if (state == 1) {
        sub.F(this);
        state = 0;
    }
    return this;
}