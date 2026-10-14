// STATUS: equivalent (tools/equiv.py level 3: 116 inputs, branch coverage 6/6)
// FUN_00207f60 @ 0x00207f60
extern "C" int __cdecl sprintf(char *, const char *, ...);
extern unsigned int DAT_004d9968;
void __fastcall __security_check_cookie(unsigned int);
struct Item { char pad[0x54]; short id; };
struct ListPart { int FUN_001c7520(); };
struct Manager { char pad[0x18]; ListPart list; Item *FUN_001c7f80(int); };
struct Context { char pad[4]; Manager *manager; };
Context * __cdecl FUN_001c3d90();
struct Resource {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
 virtual void v9(int *, int *, int *, int *);
 virtual void v10(); virtual void v11();
};
struct Handle { char pad[0x30]; Resource *resource; };
struct Object {
 char pad0[0x24]; char name[0xad0]; unsigned char dirty;
 void FUN_00204e40();
 void FUN_00207580(int, int);
 Handle *FUN_00204540(const char *);
 void FUN_00207080(int);
 void FUN_00207f60();
};
void Object::FUN_00207f60() {
 unsigned int cookie=DAT_004d9968;
 if (dirty) { FUN_00204e40(); dirty=0; }
 Manager *manager=FUN_001c3d90()->manager;
 int count=manager->list.FUN_001c7520();
 for(int i=0;i<count;++i) {
  int id=manager->FUN_001c7f80(i)->id;
  char buffer[32];
  sprintf(buffer,"%s_r%03d",name,id);
  FUN_00207580(id,1);
  Handle *h=FUN_00204540(buffer);
  int a,b,c,d;
  h->resource->v9(&a,&b,&c,&d);
  h->resource->v11();
  FUN_00207080(id);
 }
 __security_check_cookie(cookie);
}
