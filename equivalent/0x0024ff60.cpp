// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 14/14)
// audio::SeqCommandCondition::vfunc_0 @ 0x0024ff60
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"

namespace audio {
struct Context;
struct Node { virtual void slot0(); virtual void slot1(); virtual void slot2(Context*); void* next; };
struct Data_24ff60 { char pad[12]; void* first; char pad2[4]; char expression[1]; };
struct Temp_24ff60 { char bytes[12]; void FUN_0023fac0(); bool FUN_00240380(const char*); void FUN_00240060(); };
struct Source_24ff60 { char pad[0x5c]; char value[1]; };
struct SeqCommandCondition;
struct Context { char pad[0x3c]; Source_24ff60* source; int state; unsigned int FUN_0025dbd0(SeqCommandCondition*); };
struct SeqCommand { virtual unsigned int vfunc_0(Context*); virtual void vfunc_1(); char pad[4]; Data_24ff60* data; };
struct SeqCommandCondition : SeqCommand { Node* current; virtual unsigned int vfunc_0(Context*); };
}
void __cdecl FUN_002613b0(void*, audio::Temp_24ff60*, void*);
unsigned int audio::SeqCommandCondition::vfunc_0(Context* context) {
 unsigned int state = context->state;
 if(state != 0 && state != 4) return state - 4;
 if(current == (Node*)-1) {
  Temp_24ff60 temp;
  temp.FUN_0023fac0();
  FUN_002613b0(context->source->value, &temp, data->expression);
  if(temp.FUN_00240380(DAT_00429b50)) {
   void* first = data->first;
   current = first ? (Node*)((char*)first - 4) : 0;
  } else current = 0;
  temp.FUN_00240060();
 }
 if(!current) return context->FUN_0025dbd0(this);
 current->slot2(context);
 void* next = current->next;
 current = next ? (Node*)((char*)next - 4) : 0;
 return (hulk_uintptr)current;
}