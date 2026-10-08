// Same code shape as 0x000862b0 (propagated; names are from that function)
class C { char pad[0x2c]; public: unsigned int f(); }; unsigned int C::f(){ return *(unsigned int*)((char*)this+0x2c); }