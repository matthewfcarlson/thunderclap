// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 6/6)
// FUN_001d5630 @ 0x001d5630
struct Query { void FUN_0008ced0(int,int,unsigned*,int,int,int); };
extern "C" Query* __cdecl FUN_0008ceb0(int,int,unsigned*,int,int,int);
extern "C" unsigned __cdecl FUN_00266da0(unsigned);
struct Owner;
struct Entry;
struct Object { char pad[0x9c]; unsigned value; Object* FUN_001d7890(Owner*,int); void FUN_001d7490(Entry*); };
extern "C" Object* __cdecl FUN_00263ea0(unsigned);
struct Entry { char pad[0x1c]; Object* object; char pad20[2]; unsigned char enabled; char pad23[0xa9-0x23]; unsigned char flag; };
struct Table { Entry* FUN_001c59d0(unsigned); };
struct Manager { char pad[12]; Table* table; void FUN_001c3a40(unsigned,unsigned); };
extern "C" Manager* __cdecl FUN_001c3d90();
struct Owner { char pad[0xb0]; unsigned char flag; Object* target(unsigned,unsigned); };
Object* Owner::target(unsigned a,unsigned b) {
 unsigned size;
 Query* q=FUN_0008ceb0(10,0,&size,0,0,0);
 q->FUN_0008ced0(10,0,&size,0,0,0);
 if(size<0xc800) return 0;
 unsigned old=FUN_00266da0(10);
 Object* obj=FUN_00263ea0(0x278);
 if(obj) obj=obj->FUN_001d7890(this,0);
 FUN_00266da0(old);
 unsigned v=obj->value;
 FUN_001c3d90()->FUN_001c3a40(a,v);
 Entry* entry=FUN_001c3d90()->table->FUN_001c59d0(a);
 if(entry) { entry->enabled=1; entry->object=obj; entry->flag=flag; obj->FUN_001d7490(entry); }
 return obj;
}