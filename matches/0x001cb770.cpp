class Item { public: virtual void A(); virtual void B(); };
class Owner { char pad[0x400]; Item* item; public: void Set(Item* p); };
void Owner::Set(Item* p) { if (p) p->A(); if (item) item->B(); item = p; }