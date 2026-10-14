// STATUS: equivalent (tools/equiv.py level 3: 190 inputs, branch coverage 12/12)
// FUN_002312b0 @ 0x002312b0
struct Key_2312b0 { unsigned low, high; };
struct Table_2312b0 { unsigned capacity; char pad[20]; void **entries; Key_2312b0 *keys; unsigned sentinel; };
struct Probe_2312b0 { Table_2312b0 *table; unsigned unused; unsigned low, high, index, step; void * FUN_002312b0(unsigned lo, unsigned hi); };
void * Probe_2312b0::FUN_002312b0(unsigned lo, unsigned hi) {
 Table_2312b0 *t = table;
 low = lo; high = hi;
 index = (t->capacity - 1) & lo;
 unsigned stride = (((lo >> 9) | (hi << 23)) & 0xfe) | 1;
 step = stride;
 unsigned count = 0;
 while (table->entries[index] != 0) {
  unsigned i = index;
  if (t->keys[i].low == lo && t->keys[i].high == hi) break;
  if (t->entries[i] == &t->sentinel) break;
  ++count;
  if (count > t->capacity - 1) return 0;
  index = (i + stride) & (t->capacity - 1);
 }
 return t->entries[index];
}