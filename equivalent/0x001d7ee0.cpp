// STATUS: equivalent (tools/equiv.py level 3: 3027 inputs, branch coverage 31/32, incomplete)
// FUN_001d7ee0 @ 0x001d7ee0
struct Ref { virtual void retain(); virtual void release(); };
struct State { int FUN_001d4de0(); };
struct Display { virtual void v0(); virtual void v1(); virtual void v2(); virtual void enable(int); virtual void v4(); virtual void v5(); virtual void v6(); virtual void refresh(); void FUN_002ef8b0(int); };
struct Holder { char pad[16]; Display* display; };
struct Object { char pad0[0xa0]; Holder* holder; char pad1[0x48]; State* state; char pad2[0x24]; Ref* current;
void FUN_001d71e0(Ref*); void FUN_001d7510(); void FUN_0027d4f0(int); void target(Ref*);
};
void Object::target(Ref* incoming) {
 if(current==incoming) return;
 if(current) { current->release(); current=0; }
 int mode=state->FUN_001d4de0();
 if(incoming) {
 FUN_001d71e0((mode==8 || mode==9)?0:incoming);
 incoming->retain();
 if(current) current->release();
 current=incoming;
 if(holder && holder->display) { Display* d=holder->display; d->FUN_002ef8b0(0); d->refresh(); }
 if(holder && holder->display) holder->display->enable(1);
 FUN_0027d4f0(5);
 } else {
 FUN_001d7510();
 if(holder && holder->display) {
 holder->display->enable(1);
 if(mode==8 || mode==9) { Display* d=holder ? holder->display : 0; d->refresh(); }
 }
 }
}
