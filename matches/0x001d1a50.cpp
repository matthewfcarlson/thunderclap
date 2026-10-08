typedef unsigned int u32;
void FUN_002133d0(u32, u32);
class C { public: char pad[8]; u32 member; bool target(u32 arg); };
bool C::target(u32 arg) { FUN_002133d0(member, arg); return true; }