typedef unsigned int uint;
struct Other_2dfc90 {
    void g(int a, int b);
};
struct Data_2dfc90 {
    char pad[12];
    uint count;
    char pad2[12];
    int data;
};
struct Src_2dfc90 {
    char pad[32];
    int data;
};
struct Obj_2dfc90 {
    char pad[8];
    Other_2dfc90* p;
    void f(Src_2dfc90* s, Data_2dfc90* d);
};
void Obj_2dfc90::f(Src_2dfc90* s, Data_2dfc90* d) {
    uint n = 0;
    if (d->count > 0) {
        int off = 0;
        do {
            ((Other_2dfc90*)((char*)p + off))->g(s->data + off, d->data + off);
            n++;
            off += 0x40;
        } while (n < d->count);
    }
}
