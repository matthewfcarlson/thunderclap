struct Block { unsigned int x[16]; };
class Target { char pad[0x34]; public: void Copy(const Block* src); };
void Target::Copy(const Block* src) { *(Block*)((char*)this+0x34) = *src; }