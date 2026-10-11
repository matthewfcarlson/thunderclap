extern int gCount;
class Item {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    char pad14[4];
    Item* next;
    unsigned int flags;
    void cleanup(int, int);
};
class Obj {
  public:
    Item* first;
    char pad04[0x18];
    int value;
    Item* list;
    Item* extra;
    void run();
};
void Obj::run() {
    for (Item* i = list; i; i = i->next) {
        bool b = ((i->flags >> 2) & 1) != 0;
        if (b) {
            i->f4();
            --gCount;
            i->cleanup(8, 1);
        }
    }
    if (extra) {
        extra->f1();
        extra = 0;
    }
    if (list) {
        list->f1();
        list = 0;
    }
    value = 0;
    if (first)
        first->f1();
    first = 0;
}
