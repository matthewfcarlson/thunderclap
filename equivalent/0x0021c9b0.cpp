// STATUS: equivalent (tools/equiv.py level 3: 307 inputs, branch coverage 16/16)
// FUN_0021c9b0 @ 0x0021c9b0
struct Constant_21c9b0 { char pad0[5]; unsigned char flags; char pad6[62]; unsigned char count; };
struct Table_21c9b0 { char pad0[5]; unsigned char flags; char pad6[10]; Constant_21c9b0** entries; char pad14[32]; int capacity; };
struct State_21c9b0 { Table_21c9b0* table; char pad4[40]; int count; };
struct Context { char pad0[28]; State_21c9b0* state; void* allocator; };
struct Record_21c9b0 { int type; int value; int unused; int a; int b; };
struct Pair_21c9b0 { unsigned char type; unsigned char value; };
struct Input_21c9b0 { Constant_21c9b0* constant; char pad4[49]; Pair_21c9b0 pairs[256]; };
extern Constant_21c9b0** __cdecl FUN_0021ae40(void*, Constant_21c9b0**, int*, int, int, const char*);
extern void __cdecl FUN_00217100(void*, Table_21c9b0*, Constant_21c9b0*);
extern int __cdecl FUN_00220c10(State_21c9b0*, int, int, int);
extern void __cdecl FUN_00220bd0(State_21c9b0*, int, int, int, int);
void __cdecl FUN_0021c9b0(Context* context, Input_21c9b0* input, Record_21c9b0* result) {
 State_21c9b0* state = context->state;
 Table_21c9b0* table = state->table;
 int oldCapacity = table->capacity;
 if (state->count + 1 > oldCapacity) {
  table->entries = FUN_0021ae40(context->allocator, table->entries, &table->capacity, 4, 0x3ffff, "constant table overflow");
 }
 for (int i = oldCapacity; i < table->capacity; ++i) table->entries[i] = 0;
 table->entries[state->count] = input->constant;
 ++state->count;
 if ((input->constant->flags & 3) && (table->flags & 4)) FUN_00217100(context->allocator, table, input->constant);
 int value = FUN_00220c10(state, 0x23, 0, state->count - 1);
 result->a = -1; result->b = -1; result->type = 10; result->value = value;
 for (int j = 0; j < input->constant->count; ++j) {
  FUN_00220bd0(state, input->pairs[j].type == 5 ? 0 : 4, 0, input->pairs[j].value, 0);
 }
}
