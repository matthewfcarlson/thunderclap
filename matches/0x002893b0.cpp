extern void* g_vftable_2893b0[];
void operator delete[](void*);
class Item_2893b0 {
  public:
    virtual void Del(int);
    virtual void Release();
};
class Entity_2893b0 {
  public:
    void* vptr;
    void Fin();
};
class Animation_2893b0 : public Entity_2893b0 {
  public:
    char pad[0x24];
    int count;
    Item_2893b0** items;
    Item_2893b0* owner;
    char pad2[4];
    void* m38;
    ~Animation_2893b0();
};
Animation_2893b0::~Animation_2893b0() {
    vptr = g_vftable_2893b0;
    if (owner == 0) {
        for (int i = 0; i < count; ++i) {
            Item_2893b0* p = items[i];
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
