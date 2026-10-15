struct Item {
    char a[0x40];
    bool b;
    char c[3];
    void* p;
    bool d;
    char e[3];
    void* q;
};
class Obj {
    char a[0x4c];
    void* volatile q;
    char b[0xf8];
    void* volatile p;
    char c[4];
    Item* volatile item;

  public:
    void Set(Item* x);
};
void Obj::Set(Item* x) {
    item = x;
    if (x) {
        x->b = true;
        item->d = true;
        void* v = p;
        item->p = v;
        void* w = q;
        item->q = w;
    }
}