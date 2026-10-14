class Item_98e60 {
    char pad[0xf1];

  public:
    unsigned char value;
};
class Owner_98e60 {
    char pad[0xb0];

  public:
    Item_98e60* a;
    Item_98e60* b;
    Item_98e60* f;
    Item_98e60* c;
    Item_98e60* d;
    Item_98e60* e;
    void Clear();
};
void Owner_98e60::Clear() {
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