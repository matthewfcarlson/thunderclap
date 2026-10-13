// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_001c6e60 @ 0x001c6e60
struct Ref { virtual void AddRef(); virtual void Release(); };
struct Words3 { unsigned int x,y,z; };
struct Words6 { unsigned int a,b,c,d,e,f; };
struct Words4 { unsigned int a,b,c,d; };
extern void* __cdecl FUN_0008d6d0(unsigned int bytes);
extern void __cdecl FUN_001c6d60(void* begin, void* end);
struct Object {
 char base[8]; unsigned char flag8,flag9; char padA[2];
 Ref* first; Ref* second; void* begin; void* end; unsigned int unused1c;
 Words3 position; Words6 data; Words4 more; unsigned short mode; char pad56[2]; unsigned int zero; float scale;
 void FUN_0027af30(void* arg);
 Object* init(void* arg, Ref* a, Ref* b, unsigned int count, const Words3* p, unsigned short m, const Words6* d, const Words4* e);
};
Object* Object::init(void* arg, Ref* a, Ref* b, unsigned int count, const Words3* p, unsigned short m, const Words6* d, const Words4* e) {
 FUN_0027af30(arg);
 flag8=0; flag9=0; first=0;
 if(a) { a->AddRef(); if(first) first->Release(); }
 first=a;
 second=0;
 if(b) { b->AddRef(); if(second) second->Release(); }
 second=b;
 if(count) {
 unsigned int size=count*0xa8;
 void* allocation=FUN_0008d6d0(size);
 begin=allocation;
 if(allocation) { end=(char*)allocation+size; FUN_001c6d60(allocation,end); }
 else { begin=0; end=0; }
 } else { begin=0; end=0; }
 position.x=p->x; position.y=p->y; position.z=p->z;
 data.a=d->a; data.b=d->b; data.c=d->c; data.d=d->d; data.e=d->e; data.f=d->f;
 more.a=e->a; more.b=e->b; more.c=e->c; more.d=e->d;
 zero=0; mode=m; scale=1.0f;
 return this;
}