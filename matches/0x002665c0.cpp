class Thing { public: void First(); void Second(); Thing* Target(unsigned char); };
void __cdecl Third(Thing*);
Thing* Thing::Target(unsigned char flags) { First(); Second(); if (flags & 1) Third(this); return this; }