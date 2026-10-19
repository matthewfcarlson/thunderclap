// STATUS: equivalent (tools/equiv.py level 3: 1113 inputs, branch coverage 12/12)
// FUN_0021a020 @ 0x0021a020
struct Value_21a020 { int type; union { int bits; float number; } data; };
struct Entry_21a020 { Value_21a020 key; Value_21a020 value; int extra; };
struct Table_21a020 { char pad[7]; unsigned char shift; char pad8[4]; Value_21a020* array; Entry_21a020* entries; char pad14[8]; int count; };
// equiv-conv: FUN_00219fb0 eax edi stack
int FUN_00219fb0(Value_21a020* output, Table_21a020* table, void* context);
int __cdecl FUN_0021a020(void* context, Table_21a020* table, Value_21a020* output) {
 int index = FUN_00219fb0(output, table, context) + 1;
 int count = table->count;
 if(index < count) {
  Value_21a020* slot = table->array + index;
  while(index < count) {
   if(slot->type != 0) {
    output[0].type = 3;
    output[0].data.number = (float)(index + 1);
    Value_21a020* source = table->array + index;
    output[1].type = source->type;
    output[1].data.bits = source->data.bits;
    return 1;
   }
   ++index; ++slot;
  }
 }
 index -= count;
 int limit = (int)(1u << (table->shift & 31));
 if(index < limit) {
  Entry_21a020* entry = table->entries + index;
  while(index < limit) {
   if(entry->value.type != 0) {
    output[0].type = entry->key.type;
    output[0].data.bits = entry->key.data.bits;
    Value_21a020* source = &table->entries[index].value;
    output[1].type = source->type;
    output[1].data.bits = source->data.bits;
    return 1;
   }
   ++index; ++entry;
  }
 }
 return 0;
}
