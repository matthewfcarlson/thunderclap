class Controller {
  public:
    virtual void A();
    virtual void B();
};
class MultiController {
  public:
    char pad[0x44];
    unsigned int count;
    Controller** items;
    void Finish();
};
extern void* vt;
void Free(void*);
void __fastcall FUN_002b28d0(MultiController* self) {
    unsigned int i = 0;
    unsigned int n = self->count;
    *(void**)self = &vt;
    if (n > 0) {
        do {
            Controller** slot = &self->items[i];
            Controller* c = *slot;
            if (c) {
                c->B();
                *slot = 0;
            }
            ++i;
        } while (i < self->count);
    }
    if (self->items)
        Free(self->items);
    self->Finish();
}
