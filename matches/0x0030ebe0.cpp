struct Block_30ebe0 {
    unsigned int x[0x15];
};
struct Obj_30ebe0 {
    char pad[0x14];
    Block_30ebe0 a;
    Block_30ebe0 b;
    unsigned int c;
    void Copy(Obj_30ebe0*);
};
void Obj_30ebe0::Copy(Obj_30ebe0* src) {
    a = src->a;
    b = src->b;
    c = src->c;
}