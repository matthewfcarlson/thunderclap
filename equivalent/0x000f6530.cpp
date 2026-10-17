// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_000f6530 @ 0x000f6530
struct Triple_f6530 { unsigned x,y,z; };
struct Object {
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void setPair(unsigned a, unsigned b);
 virtual void getPair(unsigned* a, unsigned* b);
 virtual void setFirst(float a);
 virtual float getFirst();
 virtual void setSecond(float a);
 virtual float getSecond();
 char padding[0xcc];
 Triple_f6530 atD0;
 Triple_f6530 atDC;
 Triple_f6530 atE8;
 void FUN_00293a90(Triple_f6530*);
 void FUN_00293ac0(Triple_f6530*);
 void FUN_00293af0(Triple_f6530*);
};
void __cdecl FUN_000f6530(Object* source, Object* dest) {
 dest->setFirst(source->getFirst());
 dest->setSecond(source->getSecond());
 struct Frame { unsigned a, b; Triple_f6530 t; } f;   // (the original's slot order)
 source->getPair(&f.a,&f.b);
 dest->setPair(f.a,f.b);
 f.t=source->atDC;
 dest->FUN_00293a90(&f.t);
 f.t=source->atE8;
 dest->FUN_00293ac0(&f.t);
 f.t=source->atD0;
 dest->FUN_00293af0(&f.t);
}
