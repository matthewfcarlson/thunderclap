// STATUS: equivalent (tools/equiv.py level 3: 154 inputs, branch coverage 25/25)
// FUN_00336dd0 @ 0x00336dd0
extern unsigned int DAT_0055dbb4;
struct ElementType { int type; };
struct Descriptor { char pad[8]; int type; ElementType* element; };
struct Schema { char pad[0x44]; int count; Descriptor* FUN_00337090(int index); };
struct Data { int unused; Schema* schema; unsigned int* values; void FUN_00336dd0(); };
void Data::FUN_00336dd0() {
 int count = schema->count;
 for(int i=0;i<count;++i) {
  Descriptor* d = schema->FUN_00337090(i);
  switch(d->type) {
  case 4: case 10:
   values[i] = values[i] ? values[i]+DAT_0055dbb4 : 0;
   break;
  case 9: {
   ElementType* e = d->element;
   values[i] = values[i] ? values[i]+DAT_0055dbb4 : 0;
   int* block = reinterpret_cast<int*>(values[i]);
   if(block) {
    int n = block[0];
    unsigned int* first = reinterpret_cast<unsigned int*>(block+1);
    for(int j=0;j<n;++j) {
     if(e->type==4 || e->type==10) *first = *first ? *first+DAT_0055dbb4 : 0;
    }
   }
   break;
  }
  }
 }
}
