extern "C" unsigned __int64 __cdecl MakeToken(int);
class CTokenHashed { public: void* vftable; int a,b,c,d,e; CTokenHashed* Target(int p1,int p2,int p3,int p4); };
CTokenHashed* CTokenHashed::Target(int p1,int p2,int p3,int p4) {
 a=0; b=0; c=0; vftable=(void*)0x40cebc;
 unsigned __int64 v=MakeToken(p1);
 d=(int)v; e=(int)(v>>32); b=p2; c=p3; return this;
}