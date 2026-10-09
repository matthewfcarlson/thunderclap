struct C { char pad[0x54]; int check(); };
struct B { int x; void *p; };
struct A { char pad[0x3c]; B *b; char pad2[0x14]; C *c; };
struct Obj { char pad[4]; A *a; int get(); };
int Obj::get() {
    if (this->a && this->a->c && this->a->c->check()) {
        A* q = this->a;
        if (q->b) {
            void *p = q->b->p;
            if (p) return (int)p;
        }
    }
    return 0;
}
