class C { int pad[2]; public: int Get(int i); };
int C::Get(int i) { if (i >= 0 && i < 3) return ((int*)this)[2+i]; return 0; }