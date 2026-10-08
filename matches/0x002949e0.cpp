class Item { public: virtual void A(); virtual void B(); };
class Owner { public: char pad[0x3c]; Item* items[0x20]; void Clear(); };
void Owner::Clear() { for (int i = 0; i < 0x20; ++i) { if (items[i]) { items[i]->B(); items[i] = 0; } } }