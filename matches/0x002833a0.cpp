class Item { public: virtual void A(); virtual void B(); };
class Inner { public: char pad[0x14]; int value; Item *item; };
class Owner { public: Item *item; char pad[0x0c]; Inner *inner; void set(Item *p); };
void Owner::set(Item *p) { if (p) p->A(); if (item) item->B(); item=p; Inner *q=inner; if (p) p->A(); if (q->item) q->item->B(); q->item=p; q->value=0xf; }