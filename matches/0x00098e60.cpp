class Item {
    char pad[0xf1];

  public:
    unsigned char value;
};
class Owner {
    char pad[0xb0];

  public:
    Item* a;
    Item* b;
    Item* f;
    Item* c;
    Item* d;
    Item* e;
    void Clear();
};
void Owner::Clear() {
    if (a)
        a->value = 0;
    if (b)
        b->value = 0;
    if (c)
        c->value = 0;
    if (d)
        d->value = 0;
    if (e)
        e->value = 0;
    if (f)
        f->value = 0;
}