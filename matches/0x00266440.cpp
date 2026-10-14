// Same code shape as 0x002366e0 (propagated; names are from that function)
class Item_266440 {
  public:
    virtual void V0();
    virtual void V1();
};
class Owner_266440 {
  public:
    void Finish();
};
class Temp_266440 {
    char pad[8];

  public:
    void Init(Owner_266440*);
    Item_266440* First();
    Item_266440* Next();
};
void __fastcall FUN_002366e0(Owner_266440* self) {
    Temp_266440 t;
    t.Init(self);
    Item_266440* item = t.First();
    while (item) {
        item->V1();
        item = t.Next();
    }
    self->Finish();
}