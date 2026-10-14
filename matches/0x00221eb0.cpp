struct Sub_221eb0 {
    void call(struct Obj_221eb0*);
};
struct Obj_221eb0 {
    char pad[0x40];
    Sub_221eb0 sub;
    char pad2[0xc];
    int state;
    void next();
    void target();
};
void Obj_221eb0::target() {
    if (state == 1) {
        sub.call(this);
        state = 0;
    }
    next();
    state = 2;
}
