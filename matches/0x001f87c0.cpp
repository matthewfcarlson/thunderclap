class X { char pad[0x450]; public: void Set(unsigned char x); };
void X::Set(unsigned char x) { pad[0x450] = x; }