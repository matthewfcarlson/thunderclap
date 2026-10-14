struct Child_d72b0 {
    char pad[4];
    char flag;
    unsigned int GetFlags();
    void SetFlags(unsigned int);
};
struct Obj_d72b0 {
    char pad[4];
    Child_d72b0* a;
    Child_d72b0* b;
    Child_d72b0* c;
    void Update(unsigned int mask);
};
void Obj_d72b0::Update(unsigned int mask) {
    unsigned int flags = b->GetFlags();
    unsigned int keep = mask;
    flags &= 0xffffff7f;
    if (a)
        flags |= 0x80;
    if (c)
        flags |= 0x100;
    unsigned int r = flags & ~keep;
    b->SetFlags(r);
    a->flag = (char)((r >> 7) & 1);
    c->flag = (char)((r >> 8) & 1);
}
