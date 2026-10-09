int FUN_000969d0(int);
class Thing { public: char pad[0x200]; int values[64]; int count; bool Has(int x); };
bool Thing::Has(int x) { int v = FUN_000969d0(x); int i = 0; if (count > 0) { do { if (values[i] == v) return true; ++i; } while (i < count); } return false; }