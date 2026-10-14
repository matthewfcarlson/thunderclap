// Same code shape as 0x002366e0 (propagated; names are from that function)
class Item_236720 {
  public:
    virtual void V0();
    virtual void V1();
};
class Owner_236720 {
  public:
    void Finish();
};
class Temp_236720 {
    char pad[8];

  public:
    void Init(Owner_236720*);
    Item_236720* First();
    Item_236720* Next();
};
void __fastcall FUN_002366e0(Owner_236720* self) {
    Temp_236720 t;
    t.Init(self);
    Item_236720* item = t.First();
    while (item) {
        item->V1();
        item = t.Next();
    }
    self->Finish();
}