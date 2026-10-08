class Target { public: char pad[0xec]; int member; void Set(char* p); };
void Target::Set(char* p) { member = (int)p; p[0xa9] = 1; }