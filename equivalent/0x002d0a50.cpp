// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// FUN_002d0a50 @ 0x002d0a50
struct State_2d0a50 { char pad[8]; unsigned flags; }; struct Object { char p[0x14]; void* active; char q[0x38]; void* resource; char r[4]; State_2d0a50* state; void FUN_002c8a80(unsigned,void*); void FUN_002c92f0(unsigned,void*); void target(unsigned,unsigned,void*); };
// equiv-conv: FUN_002cec10 ecx edx esi
void FUN_002cec10(Object*,bool,unsigned);
// equiv-conv: FUN_002cd130 eax edx esi
void FUN_002cd130(Object*,bool,unsigned);
// equiv-conv: FUN_002c7e40 eax ecx esi
void FUN_002c7e40(Object*,bool,unsigned);
// equiv-conv: FUN_002c8130 ecx eax esi
void FUN_002c8130(bool,Object*,unsigned);
void Object::target(unsigned c,unsigned v,void* d) { bool e=d && resource; bool s; if(e) { if(state) FUN_002c8a80(v,d); else FUN_002c92f0(v,d); s=state && (state->flags&0xffffffcfU); } else s=state!=0; if(s) {if(active) FUN_002cd130(this,e,c); else FUN_002cec10(this,e,c);} else {if(active) FUN_002c7e40(this,e,c); else FUN_002c8130(e,this,c);} }