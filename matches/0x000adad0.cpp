struct Block { int x[0x11]; };
class Thing { public: char pad[0xf0]; Block data; void Copy(Block *out); };
void Thing::Copy(Block *out) { *out = data; }