struct Inner_1aea70 {
    char p[0x2c];
    float key;
};
struct Ref_1aea70 {
    Inner_1aea70* in;
    int tag;
};
struct A_1aea70 {
    char p[0x10];
    Ref_1aea70 r;
};
int Cmp(A_1aea70* q, A_1aea70* p) {
    Ref_1aea70 rp = p->r;
    float kp = rp.in->key;
    Ref_1aea70 rq = q->r;
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
