struct Entry {
    char pad[4];
    unsigned char value;
};
struct Holder {
    char pad[4];
    Entry* a;
    Entry* b;
    Entry* c;
    void set(unsigned char x);
};
void Holder::set(unsigned char x) {
    b->value = x;
    a->value = x;
    c->value = x;
}