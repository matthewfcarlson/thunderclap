class Item_add70 {
  public:
    virtual void f();
    virtual void Release();
};
extern "C" void __cdecl Free(void*);
class Owner_add70 {
  public:
    char pad[0x10];
    int count;
    Item_add70** items;
    void Clear();
};
void Owner_add70::Clear() {
    register Owner_add70* self = this;
    if (self->items != 0) {
        int i = 0;
        if (self->count > 0) {
            do {
                Item_add70** slot = self->items + i;
                Item_add70* p = *slot;
                if (p) {
                    p->Release();
                    *slot = 0;
                }
                ++i;
            } while (i < self->count);
        }
        if (self->items) {
            Free(self->items);
            self->items = 0;
        }
        self->count = 0;
    }
}