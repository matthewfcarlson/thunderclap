// STATUS: equivalent (tools/equiv.py level 3: 119 inputs, branch coverage 12/12)
// FUN_003005e0 @ 0x003005e0
struct Resource {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
};
struct Entry { char pad[12]; Resource* first; Resource* second; };
struct Item { char pad0[0x28]; int count; char pad2[4]; Entry* entries; char pad3[0x3d]; unsigned char active; };
struct Vector { char data[16]; };
struct Row { Item** begin; Item** end; char pad[0x28]; Vector a; Vector b; unsigned char active; char tail[0x1b]; void FUN_00300410(void*); };
struct Processor { void FUN_00302ef0(Vector*, Vector*, void*); void FUN_00302ed0(Resource*, Resource*, Vector*); };
struct Owner { Row* rows; char pad0[0x24]; Processor processor; char pad1[0x2173]; void* context; void FUN_003005e0(int, void*); };
void Owner::FUN_003005e0(int index, void* arg) {
 if (!rows[index].active) return;
 rows[index].FUN_00300410(context);
 processor.FUN_00302ef0(&rows[index].a, &rows[index].b, arg);
 unsigned int n = (unsigned int)(rows[index].end - rows[index].begin);
 for (unsigned int i=0; i<n; ++i) {
  Item* item = rows[index].begin[i];
  if (item->active) {
   for (int j=0; j<item->count; ++j) {
    Entry* entry=&item->entries[j];
    entry->first->v10();
    entry->second->v10();
    processor.FUN_00302ed0(entry->first, entry->second, &rows[index].b);
   }
  }
  n=(unsigned int)(rows[index].end - rows[index].begin);
 }
}
