// STATUS: equivalent (tools/equiv.py level 3: 292 inputs, branch coverage 20/20)
// FUN_00300d80 @ 0x00300d80
#include "gen/owners.h"
void __cdecl FUN_0008d330(void*);
void __cdecl FUN_0008d340(void*);
void* owners::Item_300d80::FUN_00300d80(unsigned char flags) {
 if(flags & 2) {
  int* header = reinterpret_cast<int*>(this)-1;
  int count = *header;
  owners::Item_300d80* p = this + count;
  if(count > 0) {
   do {
    --p;
    p->FUN_00300360();
    p->eEnd=p->e; if(p->e) FUN_0008d340(p->e);
    p->dEnd=p->d; if(p->d) FUN_0008d340(p->d);
    p->cEnd=p->c; if(p->c) FUN_0008d340(p->c);
    p->bEnd=p->b; if(p->b) FUN_0008d340(p->b);
    p->aEnd=p->a; if(p->a) FUN_0008d340(p->a);
   } while(--count);
  }
  if(flags & 1) FUN_0008d340(header);
  return header;
 }
 FUN_00300b50();
 if(flags & 1) FUN_0008d330(this);
 return this;
}
