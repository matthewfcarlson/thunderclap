class C { public: unsigned char Get(int i); };
unsigned char C::Get(int i) { return *((unsigned char*)(((char**)this)[i]) + 8); }