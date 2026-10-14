// Same code shape as 0x00221c40 (propagated; names are from that function)
struct Obj_30f100 {
    char pad[0x40];
    struct Sub {
        void F(Obj_30f100*);
    } sub;
    char pad2[0x0c];
    int state;
    Obj_30f100* target();
};
Obj_30f100* Obj_30f100::target() {
    if (state == 1) {
        sub.F(this);
        state = 0;
    }
    return this;
}