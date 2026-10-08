class C { public: int pad; int m[1]; int Get(int i); };
int C::Get(int i) { return m[i]; }