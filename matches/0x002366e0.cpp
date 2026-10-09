class Item { public: virtual void V0(); virtual void V1(); };
class Owner { public: void Finish(); };
class Temp { char pad[8]; public: void Init(Owner*); Item* First(); Item* Next(); };
void __fastcall FUN_002366e0(Owner* self) {
  Temp t;
  t.Init(self);
  Item* item = t.First();
  while (item) {
    item->V1();
    item = t.Next();
  }
  self->Finish();
}