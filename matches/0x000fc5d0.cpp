class Item { public: virtual void F(); };
class Container { public: char pad[0x10]; int count; Item* items[1]; int Add(Item* p); };
int Container::Add(Item* p) { items[count] = p; p->F(); count = count + 1; return count - 1; }
