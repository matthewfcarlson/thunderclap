// STATUS: equivalent (tools/equiv.py level 3: 86 inputs, branch coverage 24/24)
// FUN_001f4010 @ 0x001f4010
struct Handle { unsigned a,b; void FUN_0027af70(unsigned); };
struct Object { char pad[0x18]; unsigned ready; };
struct Entry { Handle first,second; Object* objects[4]; unsigned results[4]; char pad30[0x44]; int type; char pad78[8]; struct Block { unsigned low,high,value; char pad[0x1c]; } blocks[4]; };
extern unsigned __int64 __cdecl FUN_002672f0(unsigned,unsigned,unsigned);
extern unsigned __cdecl FUN_002673a0(unsigned,unsigned);
extern void __cdecl FUN_001f3040(Entry*,unsigned);
struct Owner { char pad[0xd4]; Entry* entries[148]; int count; unsigned FUN_001f3ec0(Object*,Entry*,Entry*,unsigned,unsigned); Entry* target(unsigned,unsigned,unsigned); };
Entry* Owner::target(unsigned arg1,unsigned arg2,unsigned arg3) {
 Entry* selected=0;
 int n=count;
 for(int i=0;i<n;++i) { Entry* e=entries[i]; if((e->first.a|e->first.b)==0) selected=e; }
 if(!selected) { if(n>=148) return selected; selected=entries[n]; if(!selected) return selected; }
 selected->first.FUN_0027af70(arg2);
 selected->second.FUN_0027af70(arg1);
 for(int j=0;j<4;++j) selected->objects[j]=0;
 for(int k=0;k<4;++k) selected->results[k]=0;
 for(int b=0;b<4;++b) { unsigned __int64 v=FUN_002672f0(0,0,0); selected->blocks[b].low=(unsigned)v; selected->blocks[b].high=(unsigned)(v>>32); selected->blocks[b].value=FUN_002673a0(0,0); }
 ++count;
 FUN_001f3040(selected,arg1);
 if(selected->type<=3 && selected->results[0]==0 && selected->objects[0] && selected->objects[0]->ready) {
 selected->results[0]=FUN_001f3ec0(selected->objects[0],selected,selected,1,0);
 if(selected->objects[1]) selected->results[1]=FUN_001f3ec0(selected->objects[1],selected,selected,1,0);
 }
 return selected;
}