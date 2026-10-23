// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 12/12)
// pure3d::DrawableContainer::vfunc_17 @ 0x002a4440
#include "gen/pure3d.h"

namespace pure3d {
struct Entry_2a4440 { char padding[8]; int key1; int key2; };
struct Group_2a4440 { int unused; Entry_2a4440** begin; Entry_2a4440** end; Entry_2a4440** capacity; };

}
void* pure3d::DrawableContainer::vfunc_17(int key1, int key2) {
 unsigned count = (unsigned)((*(Group_2a4440 * *)&this->f_4c) - (*(Group_2a4440 * *)&this->f_48));
 Group_2a4440* group = (*(Group_2a4440 * *)&this->f_48);
 for (unsigned i=0;i<count;++i,++group) {
  Entry_2a4440** entries = group->begin;
  unsigned size = (unsigned)(group->end - entries);
  for(unsigned j=0;j<size;++j) {
   Entry_2a4440* entry = entries[j];
   if(entry->key1 == key1 && entry->key2 == key2) return (void*)(entry);
  }
 }
 return (void*)(0);
}
