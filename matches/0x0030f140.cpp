struct Obj_30f140 {
    unsigned a[21];
    void copy(Obj_30f140* src);
};
void Obj_30f140::copy(Obj_30f140* src) {
    a[0] = src->a[0];
    a[1] = src->a[1];
    a[2] = src->a[2];
    a[4] = src->a[4];
    a[5] = src->a[5];
    a[6] = src->a[6];
    a[8] = src->a[8];
    a[9] = src->a[9];
    a[10] = src->a[10];
    a[20] = 2;
}