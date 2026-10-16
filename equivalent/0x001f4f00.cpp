// STATUS: equivalent (tools/equiv.py level 3: 25 inputs, branch coverage 86/86)
// FUN_001f4f00 @ 0x001f4f00
#include "decls/address.h"
typedef unsigned long U_1f4f00; typedef unsigned __int64 Q_1f4f00;
struct Pair_1f4f00 { U_1f4f00 a,b; };
U_1f4f00 __cdecl FUN_002673a0(int,int);
void __cdecl FUN_00249a90(U_1f4f00,Pair_1f4f00*);
void __cdecl FUN_0024a800(U_1f4f00,int);
void __cdecl FUN_002497e0(U_1f4f00);
void __cdecl FUN_0024af00(U_1f4f00);
bool __cdecl FUN_00249b40(U_1f4f00);
void __cdecl FUN_00240bb0();
void __cdecl FUN_002656a0();
struct Small_1f4f00 { char pad[8]; void FUN_0027b040(int); void FUN_0027af60(int,int); };
struct Block_1f4f00 { Small_1f4f00 first,second; U_1f4f00 values[8]; char pad[0x74-0x30]; U_1f4f00 type,flag; char gap[4]; struct Entry { Q_1f4f00 q; U_1f4f00 r; char pad[28]; } entries[4]; };
struct Resource_1f4f00 { void FUN_001e8ac0(); };
struct Node { U_1f4f00 unknown,handle; Resource_1f4f00* resource; U_1f4f00 other,state; unsigned char active; char pad[3]; U_1f4f00 allocation; void FUN_001f4940(); };
struct State_1f4f00 { char pad0[8]; Node* nodes[32]; int count; Node* primary; int index; char pad94[12]; Small_1f4f00 small; U_1f4f00 s8,sC,s10,s14; unsigned char s18; char padB9[7]; Node* extra[4]; U_1f4f00 padD0; Block_1f4f00* blocks[148]; U_1f4f00 reset324,reset328; U_1f4f00 pad32C; int pending; void FUN_001f46a0(); void reset(); };
void State_1f4f00::reset(){
 while(pending>0) FUN_001f46a0();
 for(int i=0;i<148;++i){
 blocks[i]->type=99; blocks[i]->flag=0;
 blocks[i]->first.FUN_0027b040(0); blocks[i]->second.FUN_0027b040(0);
 blocks[0]->values[0]=0; blocks[0]->values[4]=0;
 blocks[1]->values[1]=0; blocks[1]->values[5]=0;
 blocks[2]->values[2]=0; blocks[2]->values[6]=0;
 blocks[3]->values[3]=0; blocks[3]->values[7]=0;
 for(int j=0;j<4;++j){ Q_1f4f00 q=FUN_002672f0(0,0,0); blocks[j]->entries[j].q=q; U_1f4f00 r=FUN_002673a0(0,0); blocks[j]->entries[j].r=r; }
 }
 reset328=0; reset324=0; small.FUN_0027af60(0,0); s8=0; sC=FUN_002673a0(0,0); s10=999; s14=0; s18=0;
 for(int k=0;k<5;++k){
 Node** slot=k==0?&primary: k==1?&extra[3]:&extra[k-2];
 if(k==1) index=-1;
 Node* n=*slot;
 if(n){
 if(n->handle){ Pair_1f4f00 p={0,0}; FUN_00249a90(n->handle,&p); FUN_0024a800(n->handle,50); if(n->allocation){FUN_002497e0(n->allocation); n->allocation=0;} }
 (*slot)->FUN_001f4940(); n=*slot;
 if(n->resource) n->resource->FUN_001e8ac0();
 U_1f4f00 a=n->allocation; n->resource=0; n->state=0;
 if(a){FUN_002497e0(a); n->allocation=0;}
 if(n->handle){ FUN_00249a90(n->handle,0); FUN_0024a800(n->handle,50); FUN_0024af00(n->handle); n->handle=0; }
 n->active=0; *slot=0;
 }
 }
 for(int t=0;t<count;++t){
 Node* n=nodes[t];
 if(n->handle){Pair_1f4f00 p={0,0}; FUN_00249a90(n->handle,&p); FUN_0024a800(n->handle,50); if(n->allocation){FUN_002497e0(n->allocation); n->allocation=0;}}
 n=nodes[t];
 while(n->handle){if(FUN_00249b40(n->handle)) break; FUN_0024a800(n->handle,10); FUN_00240bb0(); FUN_002656a0();}
 n=nodes[t]; if(n->resource) n->resource->FUN_001e8ac0(); U_1f4f00 a=n->allocation; n->resource=0; n->state=0;
 if(a){FUN_002497e0(a); n->allocation=0;}
 if(n->handle){FUN_00249a90(n->handle,0); FUN_0024a800(n->handle,50); FUN_0024af00(n->handle); n->handle=0;} n->active=0;
 }
 count=0; pending=0;
}
