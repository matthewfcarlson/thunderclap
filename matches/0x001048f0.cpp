// Same code shape as 0x00102b60 (propagated; names are from that function)
class Helper { public: float f(int,int); };
class CMoveAgent { public: virtual void a(); virtual void b(); virtual void c(); virtual float d(int, int); };
extern volatile const float gZero;
float CMoveAgent::d(int x, int y) { ((Helper*)this)->f(x,y); float z=gZero; *(int*)((char*)this+8)=0; return z; }