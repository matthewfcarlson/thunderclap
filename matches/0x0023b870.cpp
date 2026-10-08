// Same code shape as 0x0023a430 (propagated; names are from that function)
class BufferStringReader { public: char pad0[0x10]; unsigned int m10; unsigned int m14; bool vfunc_6(); };
bool BufferStringReader::vfunc_6() { return m14 >= m10; }