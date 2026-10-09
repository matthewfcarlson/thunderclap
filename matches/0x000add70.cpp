class Item {
  public:
    virtual void f();
    virtual void Release();
};
extern "C" void __cdecl Free(void*);
class Owner {
  public:
    char pad[0x10];
    int count;
    Item** items;
    void Clear();
};
void Owner::Clear() {
    register Owner* self = this;
    if (self->items != 0) {
        int i = 0;
        if (self->count > 0) {
            do {
                Item** slot = self->items + i;
                Item* p = *slot;
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