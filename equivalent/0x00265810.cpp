// STATUS: equivalent (tools/equiv.py level 3: 170 inputs, branch coverage 20/20)
// FUN_00265810 @ 0x00265810
struct Request { char pad[0x100]; void* context; char pad104[8]; unsigned char flags; };
struct Task { virtual void slot0(); Task* FUN_00266890(Request*); void FUN_00266800(Request*); void FUN_00266950(int); void FUN_00266850(void*); int FUN_00266710(); };
extern void* __cdecl FUN_00263ed0(unsigned int,int);
extern void __cdecl thunk_FUN_00270a50();
struct Entry { Task* task; unsigned int value; };
struct Manager { unsigned char flags; char pad[0x13]; Entry* head; Entry* tail; Entry* begin; Entry* end; void FUN_002655b0(); void FUN_00265810(Request*,Task**); };
void Manager::FUN_00265810(Request* request,Task** output) {
 request->flags |= flags;
 Task* memory = (Task*)FUN_00263ed0(0x130,1);
 Task* task = memory ? memory->FUN_00266890(request) : 0;
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