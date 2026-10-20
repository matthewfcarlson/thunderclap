// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0031a4f0 @ 0x0031a4f0
#include "compat/ptr.h"
extern "C" void* __cdecl FUN_0008d6d0(hulk_uintptr);
struct State_31a4f0 {
 char pad0[0x20];
 float weightA, weightB;
 char pad1[0x38];
 void FUN_0031a8b0(const State_31a4f0*);
};
struct Object {
 void* begin;
 void* current;
 void* end;
 unsigned int reserved;
 State_31a4f0 state;
 unsigned int field70, field74, field78, field7c, flags, field84;
 unsigned int field88, field8c, field90, field94, field98, field9c, fielda0;
 Object* copy(const Object* src);
};
Object* Object::copy(const Object* src) {
 begin = current = end = 0;
 state.FUN_0031a8b0(&src->state);
 field70 = src->field70;
 field74 = src->field74;
 field78 = src->field78;
 field7c = src->field7c;
 flags = src->flags;
 field88 = src->field88;
 field8c = src->field8c;
 field90 = src->field90;
 field94 = src->field94;
 field98 = src->field98;
 field9c = src->field9c;
 fielda0 = src->fielda0;
 begin = FUN_0008d6d0(1000);
 if (begin) { current = begin; end = (char*)begin + 1000; }
 else { current = end = 0; }
 if ((flags & 6) == 2) { state.weightA = 1.0f; state.weightB = 0.0f; }
 else if ((flags & 6) == 4) { state.weightA = 0.0f; state.weightB = 1.0f; }
 return this;
}