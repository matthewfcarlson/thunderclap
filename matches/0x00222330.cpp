struct Bits_222330 {
    unsigned int count;
    unsigned int w[1];
};
struct Obj_222330 {
    char pad[0x10];
    Bits_222330* bits;
};
struct Owner_222330 {
    char pad[0x14];
    Obj_222330* obj;
    bool Check(Obj_222330* other);
};
bool Owner_222330::Check(Obj_222330* other) {
    if (!other)
        return false;
    Obj_222330* p = obj;
    if (!p)
        return true;
    Bits_222330* b = p->bits;
    Bits_222330* a = other->bits;
    unsigned int n = a->count;
    for (unsigned int i = 0; i < n; i++) {
        unsigned int m = 1 << (i & 31);
        if ((a->w[i >> 5] & m) && (b->w[i >> 5] & m))
            return true;
    }
    return false;
}
