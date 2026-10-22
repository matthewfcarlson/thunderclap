// STATUS: equivalent (tools/equiv.py level 3: 284 inputs, branch coverage 14/14)
// FUN_002a6930 @ 0x002a6930
#include "gen/pure3d.h"
struct TypeInfo_2a6930 { unsigned int value; }; extern TypeInfo_2a6930 DAT_004cf8e8, DAT_004cf908;
struct Resource_2a6930 { char pad[0x5c]; void* data; };
struct Entry_2a6930 { void* object; char pad[12]; };
struct Source_2a6930 { char pad[0x48]; Entry_2a6930* begin; Entry_2a6930* end; };
struct VertexList_2a6930 {
    pure3d::VertexList* FUN_002c8730(void*);
};
extern "C" void* __cdecl FUN_0008d6d0(unsigned int);
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern "C" Resource_2a6930* __cdecl FUN_00344e74(void*, int, TypeInfo_2a6930*, TypeInfo_2a6930*, int);
struct ProceduralVertexAnimController_2a6930 { char pad[0x40]; Source_2a6930* source; unsigned int field44; unsigned int count; pure3d::VertexList** items; void FUN_002a68b0(); void target(Source_2a6930*); };
void ProceduralVertexAnimController_2a6930::target(Source_2a6930* input) {
 FUN_002a68b0(); source=input;
 if (!input) return;
 count=(unsigned int)(((int)((char*)input->end-(char*)input->begin))>>4);
 items=(pure3d::VertexList**)FUN_0008d6d0(count*4);
 unsigned int index=0, offset=0;
 while(index<count) {
  items[index]=0;
  Resource_2a6930* resource=FUN_00344e74(*(void**)((char*)source->begin+offset),0,&DAT_004cf8e8,&DAT_004cf908,0);
  if(resource) {
   pure3d::VertexList* memory=(pure3d::VertexList*)FUN_0008d690(0x5c);
   pure3d::VertexList* obj=memory ? ((VertexList_2a6930*)(memory))->FUN_002c8730(resource->data) : 0;
   pure3d::VertexList** slot=items+index;
   if(obj) obj->vfunc_0();
   if(*slot) (*slot)->vfunc_1();
   *slot=obj;
  }
  ++index; offset+=16;
 }
}
