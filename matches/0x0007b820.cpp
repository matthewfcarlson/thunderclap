class Obj_7b820 {
  public:
    virtual void A();
    virtual void B();
};
class C_7b820 {
  public:
    char pad[0x374c];
    Obj_7b820* items[20];
    int count;
    int total;
    int F(Obj_7b820* p);
};
int C_7b820::F(Obj_7b820* p) {
    int i = count;
    if (i == 20)
        return -1;
    if (p)
        p->A();
    if (items[i])
        items[i]->B();
    items[i] = p;
    ++count;
    ++total;
    return i;
}