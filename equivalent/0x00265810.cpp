// STATUS: equivalent (tools/equiv.py level 3: 170 inputs, branch coverage 20/20)
// FUN_00265810 @ 0x00265810
struct Request { char pad[0x100]; void* context; char pad104[8]; unsigned char flags; };
struct LoadRequest_265810 { virtual void slot0(); LoadRequest_265810* FUN_00266890(Request*); void FUN_00266800(Request*); void FUN_00266950(int); void FUN_00266850(void*); int FUN_00266710(); };
extern void* __cdecl FUN_00263ed0(unsigned int,int);
extern void __cdecl thunk_FUN_00270a50();
struct Entry_265810 { LoadRequest_265810* task; unsigned int value; };
struct Manager_265810 { unsigned char flags; char pad[0x13]; Entry_265810* head; Entry_265810* tail; Entry_265810* begin; Entry_265810* end; void FUN_002655b0(); void FUN_00265810(Request*,LoadRequest_265810**); };
void Manager_265810::FUN_00265810(Request* request,LoadRequest_265810** output) {
 request->flags |= flags;
 LoadRequest_265810* memory = (LoadRequest_265810*)FUN_00263ed0(0x130,1);
 LoadRequest_265810* task = memory ? memory->FUN_00266890(request) : 0;
 task->slot0(); task->slot0();
 if(tail < end) {
  if(tail) { tail->task = task; tail->value=0; }
  tail = tail+1;
  if(tail==end) tail=begin;
  if(head==tail) tail = tail+(end-begin);
 }
 task->FUN_00266800(request);
 task->FUN_00266950(1);
 if(request->context) task->FUN_00266850(request->context);
 if(request->flags) {
  while(task->FUN_00266710()!=3) {
   if(task->FUN_00266710()==5) break;
   FUN_002655b0();
   thunk_FUN_00270a50();
  }
 }
 *output=task;
}