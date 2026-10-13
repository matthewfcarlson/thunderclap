// STATUS: equivalent (tools/equiv.py level 3: 1134 inputs, branch coverage 8/8)
// FUN_001e1040 @ 0x001e1040
struct Entry { unsigned int a,b,c; float priority; unsigned short d,e; };
extern void __cdecl FUN_001de140(Entry*, int, int, Entry);
void __cdecl FUN_001e1040(Entry* entries, int hole, int count, Entry value) {
 int start=hole;
 int child=2*hole+2;
 while(child<count) {
  if (entries[child].priority < entries[child-1].priority) --child;
  entries[hole].a=entries[child].a;
  entries[hole].b=entries[child].b;
  entries[hole].c=entries[child].c;
  entries[hole].priority=entries[child].priority;
  entries[hole].d=entries[child].d;
  entries[hole].e=entries[child].e;
  hole=child;
  child=2*child+2;
 }
 if(child==count) {
  entries[hole].a=entries[count-1].a;
  entries[hole].b=entries[count-1].b;
  entries[hole].c=entries[count-1].c;
  entries[hole].priority=entries[count-1].priority;
  entries[hole].d=entries[count-1].d;
  entries[hole].e=entries[count-1].e;
  hole=count-1;
 }
 FUN_001de140(entries,hole,start,value);
}