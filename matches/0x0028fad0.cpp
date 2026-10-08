class Obj { public: char pad[0xec]; unsigned int value; unsigned int get(); };
unsigned int Obj::get() { return value; }