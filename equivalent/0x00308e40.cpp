// STATUS: equivalent (tools/equiv.py level 3: 609 inputs, branch coverage 8/8)
// FUN_00308e40 @ 0x00308e40
struct Entry_308e40 {
 char base[0x1c];
 unsigned int x,y,z;
 unsigned int a,b;
 unsigned char flag;
 char padding[3];
 void FUN_002fd080();
 void FUN_002fcaf0(Entry_308e40*);
};
void __cdecl FUN_00308de0();
void* __cdecl FUN_0008d6d0(unsigned int);
void __stdcall FUN_00011520(void*,unsigned int,int,void (__cdecl*)());
struct Object {
 char pad[0x1f8];
 Entry_308e40* entries;
 int count;
 void FUN_002f75d0(Object*,int);
 void FUN_00308e40(Object* dest,int arg);
};
void Object::FUN_00308e40(Object* dest,int arg) {
 FUN_002f75d0(dest,arg);
 dest->count=count;
 if(count>0) {
  int n=count;
  unsigned int* allocation=(unsigned int*)FUN_0008d6d0((unsigned int)n*0x34+4);
  Entry_308e40* p=0;
  if(allocation) {
   p=(Entry_308e40*)(allocation+1);
   *allocation=n;
   FUN_00011520(p,0x34,n,FUN_00308de0);
  }
  dest->entries=p;
 }
 for(int i=0;i<count;++i) {
  dest->entries[i].FUN_002fd080();
  dest->entries[i].FUN_002fcaf0(&entries[i]);
  Entry_308e40* src=&entries[i];
  Entry_308e40* dst=&dest->entries[i];
  dst->x=src->x;
  dst->y=src->y;
  dst->z=src->z;
  dest->entries[i].a=entries[i].a;
  dest->entries[i].b=entries[i].b;
  dest->entries[i].flag=entries[i].flag;
 }
}
