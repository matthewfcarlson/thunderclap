class C { public: volatile int pad[6]; void Clear(); };
void C::Clear() { pad[6] = 0; pad[4] = 0; pad[1] = 0; pad[5] = 0; pad[3] = 0; pad[2] = 0; }