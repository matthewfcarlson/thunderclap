// STATUS: equivalent (tools/equiv.py level 3: 1314 inputs, branch coverage 29/29)
// FUN_00336dd0 @ 0x00336dd0
// FUN_00336dd0 @ 0x00336dd0
#include "decls/data/engine/movie.h"

struct ElementType { int type; };
struct Descriptor_336dd0 { char pad[8]; int type; ElementType* element; };
struct Schema_336dd0 { char pad[0x44]; int count; Descriptor_336dd0* FUN_00337090(int index); };
struct Data_336dd0 { int unused; Schema_336dd0* schema; unsigned int* values; void FUN_00336dd0(); };
void Data_336dd0::FUN_00336dd0() {
 int count = schema->count;
 for(int i=0;i<count;++i) {
  Descriptor_336dd0* d = schema->FUN_00337090(i);
  switch(d->type) {
  case 4: case 5: case 6: case 7: case 8: case 10:     // jump table 0x336ea8: types 4-8 and 10 relocate
   values[i] = values[i] ? values[i]+(*(unsigned int*)&DAT_0055dbb4) : 0;
   break;
  case 9: {
   ElementType* e = d->element;
   values[i] = values[i] ? values[i]+(*(unsigned int*)&DAT_0055dbb4) : 0;
   int* block = reinterpret_cast<int*>(values[i]);
   if(block) {
    int n = block[0];
    unsigned int* first = reinterpret_cast<unsigned int*>(block+1);
    for(int j=0;j<n;++j) {
     if(e->type==4 || e->type==10) *first = *first ? *first+(*(unsigned int*)&DAT_0055dbb4) : 0;
    }
   }
   break;
  }
  }
 }
}
