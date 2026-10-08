class Target { public: char pad[0x4a4]; int value; bool Set(int x); };
bool Target::Set(int x) { value = x; return true; }