class Small { public: void A(int); void B(); void C(); void D(); };
class Obj { public: int *p0; int p4; int *p8; int *pc; char pad10[8]; Small s18; char pad19[15]; Small s28; char pad29[63]; Small s68; Obj * Run(unsigned char flags); };
void relA(void *); void relB(void *);
Obj * Obj::Run(unsigned char flags) { if(p0) ((Small *)p0)->A(3); s68.B(); s28.C(); s18.D(); pc=p8; if(p8) relA(p8); if(flags&1) relB(this); return this; }