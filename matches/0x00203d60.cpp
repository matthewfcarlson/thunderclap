class C { char pad[0x578]; public: int Get(int index); };
int C::Get(int index) { return *(int*)((char*)this + 0x578 + index * 4); }