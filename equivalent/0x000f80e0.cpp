// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_000f80e0 @ 0x000f80e0
struct State {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void Get(int*); virtual void Set(int);
};
struct Context {
 char pad[0x24]; State* states[61];
 int mode;
 void FUN_000f7f60(int, int, int, int, int, int);
};
struct Entry { int a,b,c,state; };
struct Object {
 Context* context;
 int unused;
 Entry entries[8];
 int index;
 int mode;
 void FUN_000f80e0(int a,int slot,int c);
};
void Object::FUN_000f80e0(int a,int slot,int c) {
 int oldState;
 if(context->states[slot]) context->states[slot]->Get(&oldState); else oldState=-1;
 int newState=entries[index].state;
 if(context->states[slot]) context->states[slot]->Set(newState);
 int oldMode=context->mode;
 context->mode=mode;
 context->FUN_000f7f60(a,slot,entries[index].a,entries[index].b,entries[index].c,c);
 if(context->states[slot]) context->states[slot]->Set(oldState);
 context->mode=oldMode;
}
