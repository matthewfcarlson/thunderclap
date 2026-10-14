class Item_fdc00 {
  public:
    virtual void f();
};
class Owner_fdc00 {
  public:
    char pad[8];
    int count;
    char pad2[0x50 - 12];
    int result;
    int add(Item_fdc00*);
};
int Owner_fdc00::add(Item_fdc00* p) {
    ((Item_fdc00**)this)[3 + count] = p;
    p->f();
    result = count;
    ++count;
    return result;
}