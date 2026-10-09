struct Inner {
    char p[0x2c];
    float key;
};
struct Ref {
    Inner* in;
    int tag;
};
struct A {
    char p[0x10];
    Ref r;
};
int Cmp(A* q, A* p) {
    Ref rp = p->r;
    float kp = rp.in->key;
    Ref rq = q->r;
    float kq = rq.in->key;
    if (kq == kp) {
        unsigned pa = (unsigned)rp.in + 0x10;
        unsigned pb = (unsigned)rq.in + 0x10;
        if (pa > pb)
            return -1;
        return pa < pb;
    }
    if (rq.in->key < rp.in->key)
        return -1;
    return 1;
}
