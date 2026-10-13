// STATUS: equivalent (tools/equiv.py level 3: 307 inputs, branch coverage 16/16)
// FUN_0021c9b0 @ 0x0021c9b0
struct Constant { char pad0[5]; unsigned char flags; char pad6[62]; unsigned char count; };
struct Table { char pad0[5]; unsigned char flags; char pad6[10]; Constant** entries; char pad14[32]; int capacity; };
struct State { Table* table; char pad4[40]; int count; };
struct Context { char pad0[28]; State* state; void* allocator; };
struct Record { int type; int value; int unused; int a; int b; };
struct Pair { unsigned char type; unsigned char value; };
struct Input { Constant* constant; char pad4[49]; Pair pairs[256]; };
extern Constant** __cdecl FUN_0021ae40(void*, Constant**, int*, int, int, const char*);
extern void __cdecl FUN_00217100(void*, Table*, Constant*);
extern int __cdecl FUN_00220c10(State*, int, int, int);
extern void __cdecl FUN_00220bd0(State*, int, int, int, int);
void __cdecl FUN_0021c9b0(Context* context, Input* input, Record* result) {
 State* state = context->state;
 Table* table = state->table;
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
