class Item_2366e0 {
  public:
    virtual void V0();
    virtual void V1();
};
class Owner_2366e0 {
  public:
    void Finish();
};
class Temp_2366e0 {
    char pad[8];

  public:
    void Init(Owner_2366e0*);
    Item_2366e0* First();
    Item_2366e0* Next();
};
void __fastcall FUN_002366e0(Owner_2366e0* self) {
    Temp_2366e0 t;
    t.Init(self);
    Item_2366e0* item = t.First();
    while (item) {
        item->V1();
        item = t.Next();
    }
    self->Finish();
}