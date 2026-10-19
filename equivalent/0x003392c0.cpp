// STATUS: equivalent (tools/equiv.py level 3: 1794 inputs, branch coverage 16/16)
// FUN_003392c0 @ 0x003392c0
// FUN_003392c0 @ 0x003392c0
#include "decls/data/engine/unknown.h"

struct State;
int __cdecl FUN_00212d70(State*);
// equiv-conv: FUN_003391f0 esi
void __cdecl FUN_003391f0(State*);
void __cdecl FUN_00212ed0(State*,int);
void __cdecl FUN_00213600(State*,int);
int __cdecl FUN_00212f00(State*,int);
int __cdecl FUN_00213120(State*,int);
void __cdecl FUN_00212d80(State*,int);
void __cdecl FUN_002135a0(State*,int,const char*);
void __cdecl FUN_00213640(State*,int,int);
int __cdecl FUN_003392c0(State* state,int index) {
 if(index<=0 && index>-10000) index=index+FUN_00212d70(state)+1;
 FUN_003391f0(state);
 FUN_00212ed0(state,index);
 FUN_00213600(state,-2);
 int length=-1;
 if(FUN_00212f00(state,-1)==3) length=FUN_00213120(state,-1);
 FUN_00212d80(state,-3);
 if(length>=0) return length;
 FUN_002135a0(state,index,((char*)&DAT_00426788));
 length=-1;
 if(FUN_00212f00(state,-1)==3) length=FUN_00213120(state,-1);
 FUN_00212d80(state,-2);
 if(length>=0) return length;
 int count=1;
 FUN_00213640(state,index,count);
 while(FUN_00212f00(state,-1)!=0) {
 FUN_00212d80(state,-2);
 ++count;
 FUN_00213640(state,index,count);
 }
 FUN_00212d80(state,-2);
 return count-1;
}
