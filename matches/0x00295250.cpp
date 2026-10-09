class Other { public: int g(int); };
class C { char pad[0x34]; int value; public: bool f(int x); };
bool C::f(int x) { int r = ((Other*)this)->g(x); if (r >= 0) { value = r; return true; } return false; }