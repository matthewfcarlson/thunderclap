class Item {
  public:
    char pad[0x28];
    char flag;
};
class Manager {
  public:
    char pad[0x10];
    int count;
    int capacity;
    Item** items;
};
class Obj {
  public:
    void Process(Item*);
};
class Service {
  public:
    void** vt;
};
Service* GetService();
void __stdcall FUN_001c8000(Manager* m) {
    if (m) {
        int i = 0;
        if (m->capacity > 0)
            do {
                Item* item;
                if (i < m->count)
                    item = m->items[i];
                else
                    item = 0;
                if (item->flag) {
                    Service* s = GetService();
                    Obj* o = (Obj*)s->vt[49];
                    o->Process(item);
                } else {
                    Service* s = GetService();
                    Obj* o = (Obj*)s->vt[48];
                    o->Process(item);
                }
                ++i;
            } while (i < m->capacity);
    }
}
