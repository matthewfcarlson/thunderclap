class C { public: int pad[2]; int f(int i); };
int C::f(int i) { if (i < 0 || i >= 1) return 0; return pad[2 + i]; }