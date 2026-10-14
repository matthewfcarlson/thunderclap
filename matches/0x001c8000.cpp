class Item_1c8000 {
  public:
    char pad[0x28];
    char flag;
};
class Manager_1c8000 {
  public:
    char pad[0x10];
    int count;
    int capacity;
    Item_1c8000** items;
};
class Obj_1c8000 {
  public:
    void Process(Item_1c8000*);
};
class Service_1c8000 {
  public:
    void** vt;
};
Service_1c8000* GetService();
void __stdcall FUN_001c8000(Manager_1c8000* m) {
    if (m) {
        int i = 0;
        if (m->capacity > 0)
            do {
                Item_1c8000* item;
                if (i < m->count)
                    item = m->items[i];
                else
                    item = 0;
                if (item->flag) {
                    Service_1c8000* s = GetService();
                    Obj_1c8000* o = (Obj_1c8000*)s->vt[49];
                    o->Process(item);
                } else {
                    Service_1c8000* s = GetService();
                    Obj_1c8000* o = (Obj_1c8000*)s->vt[48];
                    o->Process(item);
                }
                ++i;
            } while (i < m->capacity);
    }
}
