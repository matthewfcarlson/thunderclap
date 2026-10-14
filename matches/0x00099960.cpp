struct Sub_99960 {
    void Fn();
};
struct Obj_99960 {
    char pad[0xc4];
    Sub_99960* m;
    void Fn();
};
void Obj_99960::Fn() {
    Sub_99960* p = m;
    p = (Sub_99960*)((char*)p + 0x218);
    p->Fn();
}
