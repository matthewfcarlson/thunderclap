extern void* g_vftable[];
void operator delete[](void*);
class Item {
  public:
    virtual void Del(int);
    virtual void Release();
};
class Base {
  public:
    void* vptr;
    void Fin();
};
class Obj : public Base {
  public:
    char pad[0x24];
    int count;
    Item** items;
    Item* owner;
    char pad2[4];
    void* m38;
    ~Obj();
};
Obj::~Obj() {
    vptr = g_vftable;
    if (owner == 0) {
        for (int i = 0; i < count; ++i) {
            Item* p = items[i];
            if (p)
                p->Del(1);
        }
        operator delete[](m38);
    } else {
        for (int i = 0; i < count; ++i)
            items[i]->Release();
        if (m38)
            owner->Release();
    }
    operator delete[](items);
    if (owner) {
        owner->Release();
        owner = 0;
    }
    Fin();
}
