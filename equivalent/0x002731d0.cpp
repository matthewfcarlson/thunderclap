// STATUS: equivalent (tools/equiv.py level 3: 91 inputs, branch coverage 29/36, incomplete)
// FUN_002731d0 @ 0x002731d0
struct Item;
struct Worker { int FUN_00272880(); int FUN_00272a20(); unsigned char FUN_00272b50(); void FUN_00272aa0(Item*); };
struct Item { virtual void destroy(int); virtual int result(); virtual void unused(); virtual Worker* worker(); virtual int process(); Item* next; };
struct Lock { virtual void enter(); virtual void leave(); };
struct Signal { int value; };
void __cdecl FUN_0026d890(Signal*);
void __cdecl FUN_0026d8a0(Signal*);
struct State { char pad0[12]; Lock lock; char pad10[0x54]; unsigned char stopped; char pad65[3]; Signal ready; Item* heads[3]; Item* tails[3]; Signal done; unsigned char requeue; char pad89[3]; int count; Item* FUN_00273140(int*); };
int __cdecl FUN_002731d0(State* s) {
 unsigned char pending=0;
 FUN_0026d890(&s->ready);
 while (!s->stopped) {
  int index;
  Item* item=s->FUN_00273140(&index);
  Worker* w=item->worker();
  int result;
  if(w->FUN_00272880()!=0 && w->FUN_00272880()!=1) { result=item->process(); if(result==1) result=item->result(); }
  else result=item->result();
  if(pending==1 && w->FUN_00272880()==0 && w->FUN_00272a20()==2 && w->FUN_00272b50()==1) { w->FUN_00272aa0(item); FUN_0026d890(&s->done); pending=0; }
  bool enqueue=false, dispose=false, special=false;
  if(result==2) enqueue=true;
  else if(result==1) dispose=true;
  else if(result==0) {
   int mode=w->FUN_00272a20();
   if(mode==0) dispose=true;
   else if(mode==1) enqueue=true;
   else if(mode==2) { w->FUN_00272aa0(item); FUN_0026d890(&s->done); if(s->requeue) { enqueue=true; special=true; } else dispose=true; }
  }
  if(enqueue) { s->lock.enter(); if(!s->tails[index]) s->tails[index]=item; item->next=s->heads[index]; s->heads[index]=item; ++s->count; s->lock.leave(); FUN_0026d8a0(&s->ready); if(special) { s->requeue=0; pending=1; } }
  else if(dispose) item->destroy(1);
  s->lock.enter(); --s->count; s->lock.leave(); FUN_0026d890(&s->ready);
 }
 return 0;
}