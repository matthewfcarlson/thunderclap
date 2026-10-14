// STATUS: equivalent (tools/equiv.py level 3: 292 inputs, branch coverage 20/20)
// FUN_00300d80 @ 0x00300d80
void __cdecl FUN_0008d330(void*);
void __cdecl FUN_0008d340(void*);
struct Item {
 void* a; void* aEnd; char pad0[8];
 void* b; void* bEnd; char pad1[8];
 void* c; void* cEnd; char pad2[8];
 void* d; void* dEnd; char pad3[8];
 void* e; void* eEnd; char pad4[36];
 void FUN_00300360();
 void FUN_00300b50();
 void* destroy(unsigned char flags);
};
void* Item::destroy(unsigned char flags) {
 if(flags & 2) {
  int* header = reinterpret_cast<int*>(this)-1;
  int count = *header;
  Item* p = this + count;
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
