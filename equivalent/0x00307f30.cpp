// STATUS: equivalent (tools/equiv.py level 3: 44 inputs, branch coverage 18/18)
// FUN_00307f30 @ 0x00307f30
struct Entry { unsigned a,b; void* resource; unsigned char c,d; char pad[2]; };
extern "C" void __cdecl FUN_0008d340(void*);
extern "C" void* __cdecl FUN_0008d6d0(unsigned);
struct Flags { int size; int capacity; unsigned char* data; void FUN_003048a0(int); };
struct Object { int count; Entry* entries; Flags flags; void FUN_00307f30(int); };
void Object::FUN_00307f30(int n) {
 Entry* old=entries;
 if(old) {
  int* header = reinterpret_cast<int*>(old)-1;
  int oldCount=*header;
  for(int i=oldCount-1;i>=0;--i) FUN_0008d340(old[i].resource);
  FUN_0008d340(header);
 }
 flags.size=0;
 count=n;
 int* allocation=static_cast<int*>(FUN_0008d6d0((unsigned)n*16+4));
 Entry* fresh=0;
 if(allocation) {
  *allocation=n;
  fresh=reinterpret_cast<Entry*>(allocation+1);
  for(int i=0;i<n;++i) { fresh[i].a=0; fresh[i].b=0; fresh[i].resource=0; fresh[i].c=0; fresh[i].d=0; }
 }
 entries=fresh;
 flags.FUN_003048a0(count);
 for(int i=0;i<count;++i) {
  if(flags.size>=flags.capacity) flags.FUN_003048a0(flags.capacity*2);
  int next=flags.size+1;
  flags.size=next;
  flags.data[next-1]=1;
 }
}