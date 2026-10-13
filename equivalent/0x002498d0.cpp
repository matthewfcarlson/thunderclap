// STATUS: equivalent (tools/equiv.py level 3: 2983 inputs, branch coverage 32/32)
// FUN_002498d0 @ 0x002498d0
extern "C" double __cdecl sqrt(double);
struct Voice { float value; int FUN_0025d3e0(); void FUN_0025d3f0(unsigned*); void FUN_0025dfc0(unsigned,unsigned); };
struct Link { Link* next; };
struct List { char pad[0x48]; Link* head; };
struct Item { char pad0[8]; Voice* voice; int state; unsigned char flag; char pad11[3]; int blocked; unsigned a,b,c; float magnitude; unsigned d; char pad2c[4]; List* list; Link link; };
// equiv-conv: run ebx
void run(Item* self) {
 for (;;) {
  int old=self->voice->FUN_0025d3e0();
  if(old==0) {
   unsigned result=0;
   if(self->blocked==0) {
    Link* p=self->list->head;
    while(p) {
     Item* item=reinterpret_cast<Item*>(reinterpret_cast<char*>(p)-0x34);
     if(item!=self && item->state!=0 && item->state!=5) {
      item->state=5; item->a=0; item->b=0; item->d=0; item->c=0;
      int status=item->voice->FUN_0025d3e0();
      if(status>=1 && status<=4) item->voice->FUN_0025d3f0(&result);
      else result=0;
      break;
     }
     p=item->link.next;
    }
   }
   self->voice->value=(float)sqrt(self->magnitude);
   self->voice->FUN_0025dfc0(result,self->flag);
  } else if(old>1 && old<=4) self->state=4;
  if(old==self->voice->FUN_0025d3e0()) break;
 }
}