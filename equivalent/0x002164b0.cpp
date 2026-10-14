// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 21/21)
// FUN_002164b0 @ 0x002164b0
struct Object;
struct State_2164b0 { char pad[0x28]; Object* gray; };
struct Value_2164b0 { int type; Object* object; };
struct Object {
 char pad[4]; unsigned char type; unsigned char flags; char pad6[2];
 union { Object* reference; Value_2164b0* value; } data;
 Value_2164b0 embedded;
 char pad14[4]; Object* tableNext;
 char pad1c[0x24]; Object* threadNext;
 char pad44[8]; Object* protoNext;
};
void __cdecl FUN_002164b0(State_2164b0* state, Object* object) {
 object->flags &= 0xfc;
 for (;;) {
  switch (object->type) {
  case 7: {
   unsigned char flags = object->flags;
   Object* next = object->data.reference;
   object->flags = flags | 4;
   if (!next || !(next->flags & 3)) return;
   next->flags &= 0xfc;
   object = next;
   break;
  }
  case 10: {
   Value_2164b0* value = object->data.value;
   if (value != &object->embedded) return;
   if (value->type >= 4) {
    Object* next = value->object;
    if (next->flags & 3) FUN_002164b0(state, next);
   }
   object->flags |= 4;
   return;
  }
  case 6: object->data.reference = state->gray; state->gray = object; return;
  case 5: object->tableNext = state->gray; state->gray = object; return;
  case 8: object->protoNext = state->gray; state->gray = object; return;
  case 9: object->threadNext = state->gray; state->gray = object; return;
  default: return;
  }
 }
}
