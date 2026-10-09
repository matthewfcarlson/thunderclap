class Item { public: virtual void First(); virtual void Second(); };
class Owner { public: char pad[0x18]; Item** items; void Set(int index, Item* value); };
void Owner::Set(int index, Item* value) { Item** p = items + index; if (value) value->First(); if (*p) (*p)->Second(); *p = value; }