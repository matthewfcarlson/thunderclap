struct Entry_d6fb0 {
    char pad[4];
    unsigned char value;
};
struct Holder_d6fb0 {
    char pad[4];
    Entry_d6fb0* a;
    Entry_d6fb0* b;
    Entry_d6fb0* c;
    void set(unsigned char x);
};
void Holder_d6fb0::set(unsigned char x) {
    b->value = x;
    a->value = x;
    c->value = x;
}