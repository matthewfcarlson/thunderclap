extern "C" int Alloc(int);
class Inner { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); virtual void Send(int, int); };
class Obj { public: virtual void v0(); Obj* Init(); char pad[12]; Inner* inner; };
extern "C" unsigned char gEnabled;
extern "C" Obj* gObject;
void Target() { if (gEnabled && gObject == 0) { Obj* p=(Obj*)Alloc(0x20); if(p) p=p->Init(); else p=0; gObject=p; gObject->v0(); gObject->inner->Send(0x444d4c42,1); } }
