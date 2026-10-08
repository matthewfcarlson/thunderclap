class C { public: float arr[1]; void F(int i, float v); };
void C::F(int i, float v) { arr[i * 3 + 0x57] = v; }