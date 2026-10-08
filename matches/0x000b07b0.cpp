class Object { public: char pad[0x490]; int value; unsigned char Set(int x); };
unsigned char Object::Set(int x) { value = x; return 1; }