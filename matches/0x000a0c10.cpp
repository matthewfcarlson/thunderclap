class Thing { char pad[0x498]; public: int value; void Set(int x); };
void Thing::Set(int x) { value = x; }