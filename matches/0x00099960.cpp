struct Sub_99960 {
    void Fn(int, int);
};
struct Obj_99960 {
    char pad[0xc4];
    Sub_99960* m;
    void Fn(int, int);
};
void Obj_99960::Fn(int a0, int a1) {
    Sub_99960* p = m;
    p = (Sub_99960*)((char*)p + 0x218);
    p->Fn(a0, a1);
}
