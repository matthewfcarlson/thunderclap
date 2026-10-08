class Target { char pad[0xb8]; public: void Set(int value); };
void Target::Set(int value) { *(int*)((char*)this + 0xb8) = value; }