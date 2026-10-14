// STATUS: equivalent (tools/equiv.py level 3: 267 inputs, branch coverage 15/16, incomplete)
// FUN_00304930 @ 0x00304930
struct Element { unsigned int a,b,c,d,e; void FUN_00304640(); };
void* __cdecl FUN_0008d6d0(unsigned int);
void __stdcall FUN_00011520(void*, unsigned int, int, void (Element::*)());
void __cdecl FUN_0008d340(void*);
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
struct Array { volatile int count; volatile int capacity; Element* volatile data; unsigned char pad; volatile unsigned char copyMembers; void FUN_00304930(int n); };
void Array::FUN_00304930(int n) {
 if (!n) n=2;
 if (capacity>=n) return;
 unsigned int* raw=(unsigned int*)FUN_0008d6d0((unsigned int)n*20+4);
 Element* fresh=0;
 if(raw) { *raw=n; fresh=(Element*)(raw+1); FUN_00011520(fresh,20,n,&Element::FUN_00304640); }
 if(count>0) {
 if(copyMembers) { for(int i=0;i<count;++i) { volatile Element* src=data+i; volatile Element* dst=fresh+i; dst->a=src->a; dst->b=src->b; dst->c=src->c; dst->d=src->d; dst->e=src->e; } }
 else { memcpy(fresh,data,(unsigned int)count*20); }
 }
 if(data) FUN_0008d340((unsigned int*)data-1);
 data=fresh; capacity=n;
}
