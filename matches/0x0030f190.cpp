// Same code shape as 0x00221cd0 (propagated; names are from that function)
struct Sub {
    char pad[0x10];
    void f(int);
};
struct C {
    char pad[0x40];
    Sub sub;
    int state;
    void* target();
};
void* C::target() {
    if (state == 2) {
        sub.f((int)this);
        state = 0;
    }
    return (void*)&sub;
}