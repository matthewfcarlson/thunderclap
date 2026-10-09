class Ref { public: virtual void F(); };
extern int vtable;
class CSimController { public: int vt; int m; Ref* p; char pad[0x10c]; CSimController(Ref*); void Init(void*, int); };
CSimController::CSimController(Ref* q) { m=0; vt=(int)&vtable; p=q; q->F(); Init((char*)this+0xc,1); Init((char*)this+0x118,1); }