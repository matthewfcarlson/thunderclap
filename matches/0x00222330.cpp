struct Bits {
    unsigned int count;
    unsigned int w[1];
};
struct Obj {
    char pad[0x10];
    Bits* bits;
};
struct Owner {
    char pad[0x14];
    Obj* obj;
    bool Check(Obj* other);
};
bool Owner::Check(Obj* other) {
    if (!other)
        return false;
    Obj* p = obj;
    if (!p)
        return true;
    Bits* b = p->bits;
    Bits* a = other->bits;
    unsigned int n = a->count;
    for (unsigned int i = 0; i < n; i++) {
        unsigned int m = 1 << (i & 31);
        if ((a->w[i >> 5] & m) && (b->w[i >> 5] & m))
            return true;
    }
    return false;
}
