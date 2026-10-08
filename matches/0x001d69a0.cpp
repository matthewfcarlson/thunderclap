class Target { char pad[0x150]; int value; public: bool f(); };
bool Target::f() { return value != 0; }