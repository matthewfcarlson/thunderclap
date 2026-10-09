struct Inner { void Setup(); };
void Register(void*, void*);
class OmHalStream { public: int vf; char pad[0x1b8]; Inner inner; OmHalStream* Init(unsigned char flag); };
OmHalStream* OmHalStream::Init(unsigned char flag) { vf=0x42a850; inner.Setup(); if (flag & 1) Register((void*)0x4e7808,this); return this; }
