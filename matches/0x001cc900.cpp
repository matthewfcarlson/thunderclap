class C { char pad[0x1194]; public: int value; };
int __fastcall target(C* p) { return p->value; }