class Obj { public: char pad[0x379c]; int count; void remove(int); void target(); };
void Obj::target() { while (count > 0) remove(0); }