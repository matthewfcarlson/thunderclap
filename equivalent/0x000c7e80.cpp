// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000c7e80 @ 0x000c7e80
struct Resource { unsigned char bytes[8]; Resource* FUN_0027af00(); void FUN_0027af70(Resource*); void FUN_0027af50(); };
struct Entry { int type; unsigned int a,b,c,d,e,f,g,h; char pad[4]; Resource resource; char reserved[8]; unsigned int value; unsigned char flag; char end[3]; };
struct Object { char pad[0x258]; Entry entries[128]; int target(unsigned int arg1, unsigned int arg2); };
int Object::target(unsigned int arg1, unsigned int arg2) { int i; for(i=0;i<128;++i) if(entries[i].type==-1) break; if(i==128) return -1; Entry& e=entries[i]; e.type=5; Resource temporary; Resource* p=temporary.FUN_0027af00(); e.resource.FUN_0027af70(p); temporary.FUN_0027af50(); e.a=0; e.b=0; e.c=0; e.d=0; e.e=0; e.f=0; e.g=0; e.h=0; e.value=arg1; e.flag=0; return i; }