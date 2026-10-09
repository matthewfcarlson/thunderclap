class Item { public: char pad[0x1c]; float value; void update(float); };
class Owner { public: char pad[0x374c]; Item* items[20]; int count; void run(float); };
void Owner::run(float x) { for (int i = 0; i < count; ++i) items[i]->update(x + items[i]->value); }
