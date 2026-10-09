class C { public: char pad[0x48]; int field; void Target(); };
void FUN_0025dcb0(int*);
void C::Target() { FUN_0025dcb0((int*)(pad + 0x40)); field = 0; }