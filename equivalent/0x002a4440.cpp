// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 12/12)
// pure3d::DrawableContainer::vfunc_17 @ 0x002a4440
namespace pure3d {
struct Entry { char padding[8]; int key1; int key2; };
struct Group { int unused; Entry** begin; Entry** end; Entry** capacity; };
struct DrawableContainer {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual Entry* vfunc_17(int key1,int key2); virtual void vfunc_18();
 char padding[0x44]; Group* begin; Group* end;
};
Entry* DrawableContainer::vfunc_17(int key1,int key2) {
 unsigned count = (unsigned)(end - begin);
 Group* group = begin;
 for (unsigned i=0;i<count;++i,++group) {
  Entry** entries = group->begin;
  unsigned size = (unsigned)(group->end - entries);
  for(unsigned j=0;j<size;++j) {
   Entry* entry = entries[j];
   if(entry->key1 == key1 && entry->key2 == key2) return entry;
  }
 }
 return 0;
}
}
