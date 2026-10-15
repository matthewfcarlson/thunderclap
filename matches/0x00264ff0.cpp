// Same code shape as 0x002366e0 (propagated; names are from that function)
class Item_264ff0 {
  public:
    virtual void V0();
    virtual void V1();
};
class Owner_264ff0 {
  public:
    void Finish();
};
class Temp_264ff0 {
    char pad[8];

  public:
    void Init(Owner_264ff0*);
    Item_264ff0* First();
    Item_264ff0* Next();
};
void __fastcall FUN_00264ff0(Owner_264ff0* self) {
    Temp_264ff0 t;
    t.Init(self);
    Item_264ff0* item = t.First();
    while (item) {
        item->V1();
        item = t.Next();
    }
    self->Finish();
}