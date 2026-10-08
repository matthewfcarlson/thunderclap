struct Item { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); };
struct Container { char pad[0x10]; int count; char pad2[4]; Item** items; };
struct Receiver { void first(int); void second(int,Item*); };
struct Obj { Container* container; char pad[8]; Receiver* receiver; int n; };
int* __fastcall FUN_0029f280(Obj* self) { self->receiver->first(self->n); for (int i=0; i<self->n; ++i) { Container* c=self->container; Item* item = i<c->count ? c->items[i] : (Item*)0; item->f6(); self->receiver->second(i,item); } return (int*)self->receiver; }