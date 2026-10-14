struct Inner {
    int x[6];
    Inner();
};
struct Obj_67e60 {
    int v[5];
    int pad;
    Inner inner;
    Obj_67e60* Copy(const Obj_67e60*);
};
Obj_67e60* Obj_67e60::Copy(const Obj_67e60* src) {
    inner.Inner::Inner();
    v[0] = src->v[0];
    v[1] = src->v[1];
    v[2] = src->v[2];
    v[3] = src->v[3];
    v[4] = src->v[4];
    return this;
}