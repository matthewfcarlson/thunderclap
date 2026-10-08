class pddiBaseContext { char pad[0x50]; struct X { char pad[0x3e4]; int value; } *m; public: void vfunc_35(int); };
void pddiBaseContext::vfunc_35(int value) { m->value = value; }