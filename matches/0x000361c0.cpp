class C { char pad[0x1b1c]; int value; public: void F(char b); };
void C::F(char b) { if (b) ++value; else --value; }