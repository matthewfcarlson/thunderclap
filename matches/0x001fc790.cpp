class Item { public: void Clear(); };
class Thing { public: char pad[8]; int count; Item *items[1]; void ClearAll(); };
void Thing::ClearAll() { for (int i = 0; i < count; ++i) items[i]->Clear(); }