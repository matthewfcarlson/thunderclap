class d3dTexture { char pad[0xd4]; public: unsigned int vfunc_5(); };
unsigned int d3dTexture::vfunc_5() { return *(unsigned int*)((char*)this + 0xd4); }