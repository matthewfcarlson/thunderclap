struct Block { unsigned int x[16]; };
class Thing { char pad[0x88]; public: void Copy(Block *src); };
void Thing::Copy(Block *src) { *(Block*)((char*)this + 0x88) = *src; }