// Same code shape as 0x00222050 (propagated; names are from that function)
void Init();
class Obj { public: char pad[0x40]; volatile int a,b,c,d,e; Obj(); };
Obj::Obj() { Init(); c=0; b=0; a=0; d=0x3f800000; e=0; }