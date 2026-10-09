// Same code shape as 0x00221eb0 (propagated; names are from that function)
struct Sub {
    void call(struct Obj*);
};
struct Obj {
    char pad[0x40];
    Sub sub;
    char pad2[0xc];
    int state;
    void next();
    void target();
};
void Obj::target() {
    if (state == 1) {
        sub.call(this);
        state = 0;
    }
    next();
    state = 2;
}
