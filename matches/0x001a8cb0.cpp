class Item { public: virtual void A(); virtual void B(); };
class Obj { public: char pad[4]; Item *a; Item *b; Item *c; Item *d; Item *e; void Init(); void Clear(); };
void Obj::Clear() { Init(); if (a) { a->B(); a = 0; } if (b) { b->B(); b = 0; } if (c) { c->B(); c = 0; } if (d) { d->B(); d = 0; } if (e) { e->B(); e = 0; } }