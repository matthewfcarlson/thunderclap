class B { public: virtual void f0(); virtual void f1(); virtual void f2(int); };
class Aux { public: void f(); };
extern void done(void*);
class C { public: void* a; B* b; };
void __fastcall target(C* self) {
    void* p = self->a;
    if (p) {
        ((Aux*)((char*)p + 0xa0))->f();
        done(p);
        self->a = 0;
    }
    if (self->b) {
        self->b->f2(1);
        self->b = 0;
    }
}