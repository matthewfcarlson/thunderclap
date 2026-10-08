class CActorManager { public: void run(); };
class Closure0 { public: virtual void a(); virtual void b(); virtual void c(); char pad[0x18]; void (CActorManager::*fn)(); CActorManager* obj; virtual void v0(); virtual void v1(); virtual void v2(int,int,int); };
void Closure0::v2(int,int,int) { (obj->*fn)(); }