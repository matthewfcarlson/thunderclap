// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// CSoundCommand_PlayTunableEvent::vfunc_1 @ 0x001f02b0
typedef unsigned long U32;
struct Key { U32 low, high; };
struct Entry { Key key; U32 type; char pad[12]; U32 a,b,c; char tail[4]; };
struct Object { char pad[0x80]; Entry entries[4]; };
struct Lookup { Object* FUN_001f31a0(U32); };
struct Events { int FUN_001e98b0(Key*); };
struct Manager { Lookup* lookup; Events* events; };
extern Manager* DAT_004e370c;
extern unsigned __int64 __cdecl FUN_002672f0(int,int,int);
struct CSoundCommand_PlayTunableEvent {
 virtual void vfunc_0();
 virtual void vfunc_1(U32, U32);
 char pad[12]; Key key; U32 type; U32 a,b,c;
};
void CSoundCommand_PlayTunableEvent::vfunc_1(U32 arg, U32 unused) {
 if (!DAT_004e370c->events->FUN_001e98b0(&key)) return;
 Object* obj=DAT_004e370c->lookup->FUN_001f31a0(arg);
 if (!obj) return;
 for(int i=0;i<4;++i) {
  Entry& e=obj->entries[i];
  if(e.type==type && e.key.low==key.low && e.key.high==key.high) return;
 }
 for(int i=0;i<4;++i) {
  unsigned __int64 empty=FUN_002672f0(0,0,0);
  Entry& e=obj->entries[i];
  if(e.key.low==(U32)empty && e.key.high==(U32)(empty>>32)) {
   e.key.low=key.low; e.key.high=key.high; e.type=type;
   e.a=a; e.b=b; e.c=c; return;
  }
 }
}
