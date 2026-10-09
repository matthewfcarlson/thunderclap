class Item { public: virtual void f(); virtual void Release(); };
struct Record { Item* ptr; char pad[24]; };
class Owner { public: char pad[0x14]; int state; char pad2[0x10]; Record items[100]; void clear(); };
void Owner::clear() { for (int i=0;i<100;i++) { if (items[i].ptr) { items[i].ptr->Release(); items[i].ptr=0; } } state=15; }
