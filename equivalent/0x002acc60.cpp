// STATUS: equivalent (tools/equiv.py level 3: 126 inputs, branch coverage 16/16)
// FUN_002acc60 @ 0x002acc60
void* __cdecl FUN_0008d690(unsigned int);
void* __cdecl memmove(void*, const void*, unsigned int);
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
extern int DAT_004cfb20;
struct Ref_2acc60 { virtual void Add(); virtual void Release(); };
struct Created_2acc60 : Ref_2acc60 { Created_2acc60* FUN_002ac4a0(int); };
struct List_2acc60 : Ref_2acc60 { int reserved; int count; Ref_2acc60* items[9]; List_2acc60* FUN_002ab6a0(); };
struct FUN_002a3e80 : Ref_2acc60 { FUN_002a3e80(); };
namespace pure3d {
struct DefaultParticleEmitterHandler : FUN_002a3e80 { virtual void Add(); virtual void Release(); };
struct ParticleSystemLoader { virtual void V0(); int a,id,b,c,flag; Ref_2acc60* refs[8]; List_2acc60* list; ParticleSystemLoader(); };
}
pure3d::ParticleSystemLoader::ParticleSystemLoader() : a(0),id(0x1580c),b(0),c(0),flag(1),list(0) {
 for(int i=0;i<8;++i) refs[i]=0;
 Created_2acc60* p=(Created_2acc60*)FUN_0008d690(0x24);
 if(p) p=p->FUN_002ac4a0(DAT_004cfb20);
 if(p) p->Add();
 if(refs[0]) refs[0]->Release();
 refs[0]=p;
 List_2acc60* q=(List_2acc60*)FUN_0008d690(0x30);
 if(q) q=q->FUN_002ab6a0();
 if(q) q->Add();
 if(list) list->Release();
 list=q;
 void* storage=FUN_0008d690(8);
 Ref_2acc60* h= storage ? new(storage) DefaultParticleEmitterHandler : 0;
 List_2acc60* l=list;
 if(h) { memmove(&l->items[1],&l->items[0],l->count*4); l->items[0]=h; h->Add(); ++l->count; }
}
