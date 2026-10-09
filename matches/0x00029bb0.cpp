class Thing { public: virtual void A(); virtual void B(); };
class Owner { public: char pad[0x344]; int key; Thing* current; int value; void Set(int k, Thing* t, int v); };
void Owner::Set(int k, Thing* t, int v) { if (k == key) { if (t) t->A(); if (current) current->B(); current = t; value = v; } }