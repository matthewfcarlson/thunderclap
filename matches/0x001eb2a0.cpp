class Other { public: void target(int, int); };
class Thing { public: char pad[8]; unsigned char enabled; void run(int a, int b); };
void Thing::run(int a, int b) { if (enabled) ((Other*)*(void**)this)->target(a, b); }