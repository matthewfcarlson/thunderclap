struct Src_12b2f0 {
    int a, b, c;
};
struct Obj_12b2f0 {
    char pad[0x20];
    int x, y, z;
    bool operator=(const Src_12b2f0* s);
};
bool Obj_12b2f0::operator=(const Src_12b2f0* s) {
    x = s->a;
    y = s->b;
    z = s->c;
    return true;
}
