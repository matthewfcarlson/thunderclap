// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_001fa500 @ 0x001fa500
struct Value { char data[8]; void FUN_0027af30(Value*); void FUN_0027af50(); };
struct Key { Value value; unsigned char a,b; };
struct Node { char pad[16]; Value value; };
struct Allocator { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void release(Node*); };
void FUN_001f92f0();
struct Container { char pad[24]; Allocator* allocator; Node* FUN_00230ba0(void (*)(void), Key*); void FUN_00230de0(Node*); };
struct Record { Value value; unsigned char a,b; char pad[78]; };
struct Object { char pad0[0x450]; unsigned char enabled; char pad1[7]; int state; char pad2[0x284]; int count; char pad3[0x34]; Record records[15]; char pad4[0x28]; int recordCount; Container* container; void FUN_001fa3a0(int); void target(int); };
void Object::target(int mode) {
 state=mode;
 if(mode==1 && enabled) {
  for(int i=0;i<recordCount;++i) {
   for(int j=0;j<count;++j) {
    records[i].b=(unsigned char)j;
    Key key;
    key.value.FUN_0027af30(&records[i].value);
    key.a=records[i].a;
    Container* c=container;
    key.b=records[i].b;
    Node* n=c->FUN_00230ba0(FUN_001f92f0,&key);
    if(n) { c->FUN_00230de0(n); n->value.FUN_0027af50(); c->allocator->release(n); }
    key.value.FUN_0027af50();
   }
   FUN_001fa3a0(i);
  }
 }
}