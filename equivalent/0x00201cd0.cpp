// STATUS: equivalent (tools/equiv.py level 3: 267 inputs, branch coverage 15/16, incomplete)
// FUN_00201cd0 @ 0x00201cd0
struct Entry { unsigned a,b,c; void FUN_00201740(); };
extern void* __cdecl FUN_0008d6d0(unsigned);
extern void __stdcall FUN_00011520(void*,unsigned,int,void (Entry::*)());
extern void __cdecl FUN_0008d340(void*);
struct Array { volatile int count; int capacity; Entry* volatile data; unsigned char flags; unsigned char manualCopy; void grow(int n); };
void Array::grow(int n) {
 if(n==0) n=2;
 if(capacity>=n) return;
 unsigned* allocation=(unsigned*)FUN_0008d6d0((unsigned)n*12+4);
 Entry* replacement=0;
 if(allocation) { allocation[0]=n; replacement=(Entry*)(allocation+1); FUN_00011520(replacement,12,n,&Entry::FUN_00201740); }
 int oldCount=count;
 if(oldCount>0) {
  if(manualCopy) { for(int i=0;i<count;++i) { volatile Entry* src=data+i; volatile Entry* dest=replacement+i; dest->a=src->a; dest->b=src->b; dest->c=src->c; } }
  else { volatile unsigned* dest=(unsigned*)replacement; volatile unsigned* src=(unsigned*)data; unsigned words=((unsigned)oldCount*12)>>2; for(unsigned j=0;j<words;++j) dest[j]=src[j]; }
 }
 Entry* previous=data;
 if(previous) FUN_0008d340((unsigned*)previous-1);
 data=replacement; capacity=n;
}
