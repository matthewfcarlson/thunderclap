class CGolem { public: char pad[0xf0]; int value; void vfunc_8(int); };
void CGolem::vfunc_8(int x) { if (x >= 0 && x <= 4) value = x; }