class Helper { public: void* Run(); };
class Other { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void* Get(); };
struct Obj { char pad[0xa0]; Helper* p; char pad2[0x78]; Other* other; char pad3[0x44]; unsigned a,b,c; };
void __fastcall FUN_001d72a0(Obj* self) {
    unsigned* p;
    if (self->p) p=(unsigned*)((char*)self->p->Run()+0x30);
    else p=(unsigned*)self->other->Get();
    self->a=p[0]; self->b=p[1]; self->c=p[2];
}