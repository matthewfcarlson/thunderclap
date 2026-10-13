// STATUS: equivalent (tools/equiv.py level 3: 116 inputs, branch coverage 14/14)
// FUN_002a6930 @ 0x002a6930
struct TypeInfo { unsigned int value; }; extern TypeInfo DAT_004cf8e8, DAT_004cf908;
struct Resource { char pad[0x5c]; void* data; };
struct Entry { void* object; char pad[12]; };
struct Source { char pad[0x48]; Entry* begin; Entry* end; };
struct Item { virtual void retain(); virtual void release(); Item* FUN_002c8730(void*); };
extern "C" void* __cdecl FUN_0008d6d0(unsigned int);
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern "C" Resource* __cdecl FUN_00344e74(void*, int, TypeInfo*, TypeInfo*, int);
struct Owner { char pad[0x40]; Source* source; unsigned int field44; unsigned int count; Item** items; void FUN_002a68b0(); void target(Source*); };
void Owner::target(Source* input) {
 FUN_002a68b0(); source=input;
 if (!input) return;
 count=(unsigned int)(((int)((char*)input->end-(char*)input->begin))>>4);
 items=(Item**)FUN_0008d6d0(count*4);
 unsigned int index=0, offset=0;
 while(index<count) {
  items[index]=0;
  Resource* resource=FUN_00344e74(*(void**)((char*)source->begin+offset),0,&DAT_004cf8e8,&DAT_004cf908,0);
  if(resource) {
   Item* memory=(Item*)FUN_0008d690(0x5c);
   Item* obj=memory ? memory->FUN_002c8730(resource->data) : 0;
   Item** slot=items+index;
   if(obj) obj->retain();
   if(*slot) (*slot)->release();
   *slot=obj;
  }
  ++index; offset+=16;
 }
}
