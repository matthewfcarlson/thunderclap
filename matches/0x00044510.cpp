class A { public: char pad0[8]; A* next; int kind; };
class D { public: char pad0[0x14]; int value; };
bool f(A* a, int b) {
    if (!a) return false;
    A* p = 0;
    switch (a->kind) {
    case 1: p = a->next; break;
    case 5: p = a->next; if (!p) return false; p = *(A**)((char*)p + 0x148); break;
    default: return false;
    }
    if (!p) return false;
    D* d = *(D**)((char*)p + 0x11c);
    if (!d) return false;
    return d->value == b;
}