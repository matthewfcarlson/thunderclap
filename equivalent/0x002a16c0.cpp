// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 10/10)
// FUN_002a16c0 @ 0x002a16c0
void* __cdecl FUN_0008d6d0(unsigned int);
void* __cdecl FUN_00263ea0(unsigned int);
struct Element_2a16c0 { char data[20]; };
struct Light { char pad[0x12]; unsigned char enabled; Light* FUN_002a2e70(); void FUN_002a2ef0(float,float,float); void FUN_002a07a0(int); };
struct List_2a16c0 { virtual void slot0(); List_2a16c0* FUN_002a1140(unsigned int); void FUN_002a1180(int); void FUN_002a0fc0(int,Light*); };
struct Setup_2a16c0 { void FUN_002a30a0(); char bytes[12]; };
struct FUN_002c6a80 { FUN_002c6a80(); virtual void baseSlot(); char p4[8]; unsigned int flags; unsigned int mode; char p14[4]; };
namespace pure3d {
struct ShadowGenerator { virtual void generatorSlot(); unsigned int zero; Setup_2a16c0 setup; List_2a16c0* list; };
struct ShadowTraversal : FUN_002c6a80 { virtual void traversalSlot(); ShadowGenerator generator; unsigned int color,count,used; Element_2a16c0 *begin,*end; ShadowTraversal(unsigned int capacity,unsigned int n); };
ShadowTraversal::ShadowTraversal(unsigned int capacity,unsigned int n) {
 generator.zero=0;
 generator.setup.FUN_002a30a0();
 color=0xffcfcfcf; count=n; used=0;
 if(capacity>0) { unsigned int bytes=capacity*20; begin=(Element_2a16c0*)FUN_0008d6d0(bytes); if(begin) end=(Element_2a16c0*)((char*)begin+bytes); else { begin=0;end=0; } } else {begin=0;end=0;}
 flags=0x230;mode=2;
 if(count>0) {
 List_2a16c0* p=(List_2a16c0*)FUN_00263ea0(0x28);
 if(p) p=p->FUN_002a1140(count);
 generator.list=p;
 p->slot0();
 Light* light=(Light*)FUN_00263ea0(0x68);
 if(light) light=light->FUN_002a2e70();
 light->FUN_002a2ef0(0.2018f,-0.9397f,0.2761f);
 light->FUN_002a07a0(-1);
 light->enabled=1;
 generator.list->FUN_002a1180(1);
 generator.list->FUN_002a0fc0(0,light);
 }
}
}