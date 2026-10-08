struct X { unsigned int a; unsigned char b; X(unsigned int, unsigned char); };
X::X(unsigned int p, unsigned char q) : a(p), b(q) {}