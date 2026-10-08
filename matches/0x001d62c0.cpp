class Obj { public: char pad[0x100]; unsigned char value; unsigned char get(); };
unsigned char Obj::get() { return value; }
