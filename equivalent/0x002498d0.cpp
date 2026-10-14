// STATUS: equivalent (tools/equiv.py level 3: 2983 inputs, branch coverage 32/32)
// FUN_002498d0 @ 0x002498d0
extern "C" double __cdecl sqrt(double);
struct Voice_2498d0 { float value; int FUN_0025d3e0(); void FUN_0025d3f0(unsigned*); void FUN_0025dfc0(unsigned,unsigned); };
struct Link_2498d0 { Link_2498d0* next; };
struct List_2498d0 { char pad[0x48]; Link_2498d0* head; };
struct Item_2498d0 { char pad0[8]; Voice_2498d0* voice; int state; unsigned char flag; char pad11[3]; int blocked; unsigned a,b,c; float magnitude; unsigned d; char pad2c[4]; List_2498d0* list; Link_2498d0 link; };
// equiv-conv: run ebx
void run(Item_2498d0* self) {
 for (;;) {
  int old=self->voice->FUN_0025d3e0();
  if(old==0) {
   unsigned result=0;
   if(self->blocked==0) {
    Link_2498d0* p=self->list->head;
    while(p) {
     Item_2498d0* item=reinterpret_cast<Item_2498d0*>(reinterpret_cast<char*>(p)-0x34);
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