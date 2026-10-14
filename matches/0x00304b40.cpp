class Owner_304b40;
class Ref_304b40 {
  public:
    virtual void A();
    virtual void B();
    int Resolve(int, unsigned char);
    void Update(Owner_304b40*);
};
struct Entry_304b40 {
    int a;
    int b;
    unsigned char c[2];
    int x;
    int y;
};
class Owner_304b40 {
  public:
    char pad0[0x20];
    Ref_304b40* current;
    char pad24[4];
    int count;
    char pad2c[4];
    Entry_304b40* entries;
    char pad34[0x34];
    unsigned char flag;
    void Set(Ref_304b40*);
};
void Owner_304b40::Set(Ref_304b40* p) {
    if (p)
        p->A();
    if (current)
        current->B();
    current = p;
    p->Update(this);
    flag = 1;
    for (int i = 0; i < count; ++i) {
        Entry_304b40* e = (Entry_304b40*)((char*)entries + i * 0x14);
        e->x = current->Resolve(e->a, e->c[0]);
        e->y = current->Resolve(e->b, e->c[1]);
    }
}