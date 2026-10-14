// STATUS: equivalent (tools/equiv.py level 3: 267 inputs, branch coverage 15/16, incomplete)
// FUN_00304930 @ 0x00304930
struct Element_304930 { unsigned int a,b,c,d,e; void FUN_00304640(); };
void* __cdecl FUN_0008d6d0(unsigned int);
void __stdcall FUN_00011520(void*, unsigned int, int, void (Element_304930::*)());
void __cdecl FUN_0008d340(void*);
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
struct Array_304930 { volatile int count; volatile int capacity; Element_304930* volatile data; unsigned char pad; volatile unsigned char copyMembers; void FUN_00304930(int n); };
void Array_304930::FUN_00304930(int n) {
 if (!n) n=2;
 if (capacity>=n) return;
 unsigned int* raw=(unsigned int*)FUN_0008d6d0((unsigned int)n*20+4);
 Element_304930* fresh=0;
 if(raw) { *raw=n; fresh=(Element_304930*)(raw+1); FUN_00011520(fresh,20,n,&Element_304930::FUN_00304640); }
 if(count>0) {
 if(copyMembers) { for(int i=0;i<count;++i) { volatile Element_304930* src=data+i; volatile Element_304930* dst=fresh+i; dst->a=src->a; dst->b=src->b; dst->c=src->c; dst->d=src->d; dst->e=src->e; } }
 else { memcpy(fresh,data,(unsigned int)count*20); }
 }
 if(data) FUN_0008d340((unsigned int*)data-1);
 data=fresh; capacity=n;
}
