class Controller_2b28d0 {
  public:
    virtual void A();
    virtual void B();
};
class MultiController {
  public:
    char pad[0x44];
    unsigned int count;
    Controller_2b28d0** items;
    void Finish();
};
extern void* vt_2b28d0;
void Free(void*);
void __fastcall FUN_002b28d0(MultiController* self) {
    unsigned int i = 0;
    unsigned int n = self->count;
    *(void**)self = &vt_2b28d0;
    if (n > 0) {
        do {
            Controller_2b28d0** slot = &self->items[i];
            Controller_2b28d0* c = *slot;
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
