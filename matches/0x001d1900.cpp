extern "C" void __cdecl helper(int, int, int);
class Obj { public: char pad[8]; int field; bool f(int n); };
bool Obj::f(int n) { if (n < 1) return false; helper(field, 0xffffd8f0, n); return true; }