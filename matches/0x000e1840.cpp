extern int type1;
extern int type2;
extern void __cdecl Init(void *, int, int *, int *, int);
class FEParticleSystem { public: FEParticleSystem(void *, int); void *vptr; int pad4; int a; int b; void *c; char flag; char pad15[0x1f]; int last; int d; int e; int f; int g; };
FEParticleSystem::FEParticleSystem(void *arg,int unused) { a=-1; b=-1; c=arg; flag=0; vptr=(void *)0x40bff8; d=0; e=0; f=(int)0xbf800000; g=(int)0xbf800000; Init(arg,0,&type1,&type2,0); last=0; }