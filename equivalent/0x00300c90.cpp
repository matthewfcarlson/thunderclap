// STATUS: equivalent (tools/equiv.py level 3: 128 inputs, branch coverage 15/16, incomplete)
// FUN_00300c90 @ 0x00300c90
extern int DAT_004d2eec;
extern void* __cdecl FUN_0008d6d0(unsigned int size);
struct A { char data[16]; void FUN_00304300(); };
struct B { char data[64]; void FUN_00301290(); };
struct C { char data[256]; void FUN_002f7ee0(); };
struct D { char data[0x2030]; void FUN_00312d50(); };
struct Entry { char pad[0x50]; unsigned char active; char rest[0x1b]; void FUN_00300a00(); };
struct Object {
 Entry* entries; int count; unsigned int* begin; unsigned int* end; unsigned int* limit; char pad14[4]; A a; B b; C c; D d; unsigned char flag; char pad2199[3]; int mode;
 Object* FUN_00300c90();
};
Object* Object::FUN_00300c90() {
 begin=0; end=0; limit=0;
 a.FUN_00304300(); b.FUN_00301290(); c.FUN_002f7ee0(); d.FUN_00312d50();
 flag=0; mode=18;
 int n=DAT_004d2eec; count=n;
 unsigned int* allocation=(unsigned int*)FUN_0008d6d0((unsigned int)n*0x6c+4);
 Entry* list=0;
 if(allocation) { *allocation=(unsigned int)n; list=(Entry*)(allocation+1); if(n-1>=0) { Entry* item=list; unsigned int remaining=(unsigned int)n; do { item->FUN_00300a00(); ++item; } while(--remaining); } }
 entries=list;
 if(count!=0) { unsigned int bytes=(unsigned int)count*4; unsigned int* p=(unsigned int*)FUN_0008d6d0(bytes); begin=p; if(p) {end=p; limit=(unsigned int*)((char*)p+bytes);} else {end=0; limit=0;} }
 else {begin=0;end=0;limit=0;}
 if(entries->active!=1) {entries->active=1; unsigned int* p=end; if((unsigned int)p<(unsigned int)limit) {end=p+1; if(p) *p=0;} }
 return this;
}
