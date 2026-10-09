struct Ref { virtual void a(); virtual void release(); };
struct Obj { volatile unsigned vptr; char pad[0x84]; Ref* volatile ptr; void run(); };
extern void __fastcall FUN_002ef2c0(Obj*);
void Obj::run() {
    vptr = 0x4319a4;
    Ref* p = ptr;
    if (p) { p->release(); ptr = 0; }
    FUN_002ef2c0(this);
}