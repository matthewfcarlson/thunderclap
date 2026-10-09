class Item { public: virtual void f(); };
class Owner { public: char pad[8]; int count; char pad2[0x50-12]; int result; int add(Item *); };
int Owner::add(Item *p) { ((Item**)this)[3 + count] = p; p->f(); result = count; ++count; return result; }