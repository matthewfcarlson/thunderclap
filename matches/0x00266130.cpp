class X { public: char pad[9]; unsigned char field; void Set(unsigned char value); };
void X::Set(unsigned char value) { field = value; }