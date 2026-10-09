// Same code shape as 0x00059d00 (propagated; names are from that function)
class Item { public: virtual void First(); virtual void Second(); };
class Owner { char pad[0x18]; public: Item* item; void Set(Item* p); };
void Owner::Set(Item* p) { if (p) p->First(); if (item) item->Second(); item = p; }