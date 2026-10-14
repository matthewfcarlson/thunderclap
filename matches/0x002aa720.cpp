class Arg {
  public:
    int Convert();
};
class Item {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual char Test(int);
    virtual void Run(int, Arg*, int, int);
};
class Group {
    char pad[8];

  public:
    unsigned count;
    Item* items[8];
    int extra;
    void Fn(int a, Arg* b, int c);
};
void Group::Fn(int a, Arg* b, int c) {
    unsigned i = 0;
    if (count > 0) {
        Item** p = items;
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