class Owner;
class Ref {
  public:
    virtual void A();
    virtual void B();
    int Resolve(int, unsigned char);
    void Update(Owner*);
};
struct Entry {
    int a;
    int b;
    unsigned char c[2];
    int x;
    int y;
};
class Owner {
  public:
    char pad0[0x20];
    Ref* current;
    char pad24[4];
    int count;
    char pad2c[4];
    Entry* entries;
    char pad34[0x34];
    unsigned char flag;
    void Set(Ref*);
};
void Owner::Set(Ref* p) {
    if (p)
        p->A();
    if (current)
        current->B();
    current = p;
    p->Update(this);
    flag = 1;
    for (int i = 0; i < count; ++i) {
        Entry* e = (Entry*)((char*)entries + i * 0x14);
        e->x = current->Resolve(e->a, e->c[0]);
        e->y = current->Resolve(e->b, e->c[1]);
    }
}