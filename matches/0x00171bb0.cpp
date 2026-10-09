class Actor;
class Owner { char pad[0x25]; public: unsigned char flag; Actor *GetActor(); };
class Actor { char pad[0x2140]; public: unsigned char field; void SetFlag(unsigned char); void SetPosition(void *); };
class Manager { public: Owner *GetOwner(); };
class DriftToPositionAction { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void vfunc_4(); virtual void f5(); char pad1[0x18]; Owner *owner; Manager *manager; char pad24[0x2c]; unsigned char a; unsigned char b; unsigned char c; char pad53[0x0b]; };
void DriftToPositionAction::vfunc_4() {
 Owner *o = manager->GetOwner();
 if (o) {
  Actor *a = o->GetActor();
  if (a) {
   if (owner->flag && c) a->SetPosition((char*)this + 0x40);
   a->field = b;
   a->SetFlag(this->a);
  }
 }
}