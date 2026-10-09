struct Obj { char pad[0x20]; unsigned short value; };
extern "C" void FUN_001f92f0();
class R { public: Obj* find(void (*)(), void*); };
class C { public: char pad[0xc6c]; R* field; unsigned short target(int a,int b,int c,int d); };
class Cleanup { public: void go(); };
unsigned short C::target(int a,int b,int c,int d) {
    Obj* o = field->find(FUN_001f92f0, (void*)&a);
    if (!o) {
        ((Cleanup*)&a)->go();
        return 0xfffe;
    }
    unsigned short v = o->value;
    ((Cleanup*)&a)->go();
    return v;
}
