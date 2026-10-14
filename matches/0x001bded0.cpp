struct Ref_1bded0 {
    void F(void*);
};
struct Obj_1bded0 {
    char pad[0x34];
    Ref_1bded0* a;
    Ref_1bded0* b;
    void Clear(void*);
};
void Obj_1bded0::Clear(void* p) {
    if (a)
        a->F(p);
    if (b)
        b->F(p);
}