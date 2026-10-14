// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 30/30)
// FUN_002169e0 @ 0x002169e0
struct Value { int type; unsigned char* data; };
struct Entry { int unused; Value* value; int rest[2]; };
struct State { char pad0[8]; Value* boundary; char padC[8]; Entry* last; char pad18[4]; Value* first; int capacity; char pad24[4]; Entry* entries; unsigned short entryCapacity; char pad2E[18]; int type; unsigned char* data; };
void __cdecl FUN_002164b0(void*, unsigned char*);
void __cdecl FUN_00215410(State*, unsigned int);
void __cdecl FUN_002153d0(State*, int);
// equiv-conv: FUN_002169e0 edi stack
void __cdecl FUN_002169e0(State* s, void* context) {
 if(s->type >= 4 && (s->data[5]&3)) FUN_002164b0(context,s->data);
 Value* end=s->boundary;
 Value* maximum=end;
 for(Entry* e=s->entries; e<=s->last; ++e) if(maximum<e->value) maximum=e->value;
 Value* v=s->first;
 if(v<end) {
 do {
 if(v->type>=4 && (v->data[5]&3)) FUN_002164b0(context,v->data);
 ++v;
 } while(v<s->boundary);
 }
 for(;v<=maximum;++v) v->type=0;
 int used=(int)((char*)s->last-(char*)s->entries);
 used=(used>>4)<<2;
 unsigned int cap=s->entryCapacity;
 if(used<(int)cap && cap>16) FUN_00215410(s,cap>>1);
 int count=(int)((char*)maximum-(char*)s->first);
 count=(count>>3)<<2;
 if(count<s->capacity && s->capacity>90) FUN_002153d0(s,s->capacity/2);
}
