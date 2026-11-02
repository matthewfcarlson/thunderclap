// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 30/30)
// FUN_002169e0 @ 0x002169e0
struct Value_2169e0 { int type; unsigned char* data; };
struct Entry_2169e0 { int unused; Value_2169e0* value; int rest[2]; };
struct State_2169e0 { char pad0[8]; Value_2169e0* boundary; char padC[8]; Entry_2169e0* last; char pad18[4]; Value_2169e0* first; int capacity; char pad24[4]; Entry_2169e0* entries; unsigned short entryCapacity; char pad2E[18]; int type; unsigned char* data; };
extern "C" void __cdecl FUN_002164b0(void *, void *);
extern "C" void __cdecl FUN_00215410(void *, unsigned int);
extern "C" int __cdecl FUN_002153d0(void *, int);
// equiv-conv: FUN_002169e0 edi stack
extern "C" void __cdecl FUN_002169e0(void * s, void* context) {
 if(((State_2169e0 *)s)->type >= 4 && (((State_2169e0 *)s)->data[5]&3)) FUN_002164b0(context,(unsigned char *)(((State_2169e0 *)s)->data));
 Value_2169e0* end=((State_2169e0 *)s)->boundary;
 Value_2169e0* maximum=end;
 for(Entry_2169e0* e=((State_2169e0 *)s)->entries; e<=((State_2169e0 *)s)->last; ++e) if(maximum<e->value) maximum=e->value;
 Value_2169e0* v=((State_2169e0 *)s)->first;
 if(v<end) {
 do {
 if(v->type>=4 && (v->data[5]&3)) FUN_002164b0(context,(unsigned char *)(v->data));
 ++v;
 } while(v<((State_2169e0 *)s)->boundary);
 }
 for(;v<=maximum;++v) v->type=0;
 int used=(int)((char*)((State_2169e0 *)s)->last-(char*)((State_2169e0 *)s)->entries);
 used=(used>>4)<<2;
 unsigned int cap=((State_2169e0 *)s)->entryCapacity;
 if(used<(int)cap && cap>16) FUN_00215410((State_2169e0 *)((State_2169e0 *)s),cap>>1);
 int count=(int)((char*)maximum-(char*)((State_2169e0 *)s)->first);
 count=(count>>3)<<2;
 if(count<((State_2169e0 *)s)->capacity && ((State_2169e0 *)s)->capacity>90) FUN_002153d0((State_2169e0 *)((State_2169e0 *)s),((State_2169e0 *)s)->capacity/2);
}
