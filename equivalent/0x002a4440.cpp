// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 12/12)
// pure3d::DrawableContainer::vfunc_17 @ 0x002a4440
namespace pure3d {
struct Entry_2a4440 { char padding[8]; int key1; int key2; };
struct Group_2a4440 { int unused; Entry_2a4440** begin; Entry_2a4440** end; Entry_2a4440** capacity; };
struct DrawableContainer {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual Entry_2a4440* vfunc_17(int key1,int key2); virtual void vfunc_18();
 char padding[0x44]; Group_2a4440* begin; Group_2a4440* end;
};
Entry_2a4440* DrawableContainer::vfunc_17(int key1,int key2) {
 unsigned count = (unsigned)(end - begin);
 Group_2a4440* group = begin;
 for (unsigned i=0;i<count;++i,++group) {
  Entry_2a4440** entries = group->begin;
  unsigned size = (unsigned)(group->end - entries);
  for(unsigned j=0;j<size;++j) {
   Entry_2a4440* entry = entries[j];
   if(entry->key1 == key1 && entry->key2 == key2) return entry;
  }
 }
 return 0;
}
}
