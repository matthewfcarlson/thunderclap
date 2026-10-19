// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 4/4)
// FUN_002150e0 @ 0x002150e0
struct Object;
typedef void* (__cdecl *Allocator)(void*, unsigned, unsigned, unsigned);
extern void __cdecl FUN_00214e80();
extern int __cdecl FUN_002152f0(Object*, void (__cdecl*)(), int);
// equiv-conv: FUN_00214f90 esi
extern void __cdecl FUN_00214f90(Object*);
struct Internal {
 unsigned a0,a4,a8;
 Allocator allocator;
 void* context;
 unsigned flag;
 Object* owner;
 unsigned a1c;
 Object** link;
 unsigned a24,a28,a2c,a30,a34,a38,a3c;
 unsigned untouched40,a44,a48,size,a50,a54,untouched58;
 Object* parent;
 unsigned a60,untouched64,a68,untouched6c,a70;
 char tail[0x3c];
};
struct Object {
 unsigned a0;
 unsigned char type,flag;
 char pad6[10];
 Internal* internal;
 unsigned a14,untouched18,a1c,a20,untouched24,a28;
 unsigned short a2c,a2e;
 unsigned char a30,a31,a32,pad33;
 unsigned a34,a38,a3c,a40,untouched44,a48,untouched4c,a50,a54;
 Internal embedded;
};
Object* __cdecl FUN_002150e0(Allocator alloc, void* context) {
 Object* p = (Object*)alloc(context,0,0,0x108);
 if (!p) return 0;
 Internal* q=&p->embedded;
 p->a0=0;
 q->flag=1;
 p->internal=q;
 p->type=8;
 p->flag=(unsigned char)q->flag;
 p->a1c=0;p->a20=0;p->a50=0;p->a3c=0;
 p->a30=0;p->a34=0;p->a31=1;p->a38=0;p->a48=0;
 p->a2c=0;p->a2e=0;p->a32=0;p->a14=0;p->a28=0;p->a54=0;p->a40=0;
 q->allocator=alloc;q->context=context;q->parent=p;
 q->a48=0;q->a8=0;q->a4=0;q->a0=0;
 p->internal->a54=0;
 q->a3c=0;q->a44=0;q->a50=0;q->a38=3;
 q->owner=p;q->a24=0;q->link=&q->owner;q->a1c=0;
 q->a28=0;q->a2c=0;q->a30=0;q->a34=0;
 q->a60=0;q->a68=0;q->a70=0;q->size=0x108;
 if (FUN_002152f0(p,FUN_00214e80,0)) { FUN_00214f90(p); p=0; }
 return p;
}