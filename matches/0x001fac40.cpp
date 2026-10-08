class C { char pad[8]; int count; int items[1]; public: void Add(int x); };
void C::Add(int x) { items[count] = x; ++count; }