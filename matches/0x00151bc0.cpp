class Obj { public: virtual void F(); virtual void G(); };
void BaseCtor();
class Hit { public: volatile int v; char pad[0x18]; volatile int a; Obj* b; char gap[0x1c]; Hit(int p, Obj* q); };
Hit::Hit(int p, Obj* q) { BaseCtor(); v=0x41460c; a=0; b=0; *(int*)((char*)this+0x24)=0; *(int*)((char*)this+0x28)=0; *(int*)((char*)this+0x2c)=0; *(int*)((char*)this+0x30)=0; *(int*)((char*)this+0x34)=0; *(int*)((char*)this+0x38)=0; *(int*)((char*)this+0x40)=0; a=p; if(q) q->F(); if(b) b->G(); b=q; }