class Arg_2aa720 {
  public:
    int Convert();
};
class Item_2aa720 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual char Test(int);
    virtual void Run(int, Arg_2aa720*, int, int);
};
class Group_2aa720 {
    char pad[8];

  public:
    unsigned count;
    Item_2aa720* items[8];
    int extra;
    void Fn(int a, Arg_2aa720* b, int c);
};
void Group_2aa720::Fn(int a, Arg_2aa720* b, int c) {
    unsigned i = 0;
    if (count > 0) {
        Item_2aa720** p = items;
        do {
            if ((*p)->Test(b->Convert()) == 1) {
                items[i]->Run(a, b, c, extra);
                return;
            }
            ++i;
            ++p;
        } while (i < count);
    }
}