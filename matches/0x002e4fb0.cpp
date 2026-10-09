// Same code shape as 0x001c65a0 (propagated; names are from that function)
struct Inner {
    void sub();
};
struct Obj {
    char pad[4];
    Obj* target();
};
Obj* Obj::target() {
    ((Inner*)((char*)this + 4))->sub();
    return this;
}