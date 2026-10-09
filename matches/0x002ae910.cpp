class Obj { public: virtual void Release(int); virtual void Tick(); };
class Container { public: int count; Obj* items[31]; char pad[0x84-4-31*4]; Obj* ref; };
void __fastcall FUN_002ae910(Container* p) {
    Obj* r = p->ref;
    if (r) r->Release(1);
    for (int i=0; i<p->count; ++i) p->items[i]->Tick();
}