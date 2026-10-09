class Item { public: virtual void F0(); virtual void F1(); };
struct Entry { int id; char p[4]; Item* item; char tail[0x10]; };
class Owner { public: char pad[0x20]; Entry entries[100]; void Remove(int id); };
void Owner::Remove(int id) { int i=0; while (entries[i].item==0 || entries[i].id!=id) { ++i; if (i>=100) return; } if (entries[i].item) { entries[i].item->F1(); entries[i].item=0; } }