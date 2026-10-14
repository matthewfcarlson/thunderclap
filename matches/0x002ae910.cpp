class Obj_2ae910 {
  public:
    virtual void Release(int);
    virtual void Tick();
};
class Container_2ae910 {
  public:
    int count;
    Obj_2ae910* items[31];
    char pad[0x84 - 4 - 31 * 4];
    Obj_2ae910* ref;
};
void __fastcall FUN_002ae910(Container_2ae910* p) {
    Obj_2ae910* r = p->ref;
    if (r)
        r->Release(1);
    for (int i = 0; i < p->count; ++i)
        p->items[i]->Tick();
}