// STATUS: equivalent (tools/equiv.py level 3: 20026 inputs, branch coverage 12/12)
// core::Drive::vfunc_3 @ 0x00272df0
#include "compat/ptr.h"
#include "decls/data/records.h"

// core::Drive::vfunc_3 (records.h CoreDrive): runs the pending requests that belong to the calling thread, then the
// drive's callback with the completed request's result (under the IMutable lock at +0xc)
struct Node { virtual void destroy(int); virtual void n1(); virtual void n2(); virtual void n3(); virtual void n4(); virtual void n5(); virtual void n6(); virtual void process(); Node* next; bool FUN_00273680(CoreThread*); };
struct Lock_272df0 { virtual void acquire(); virtual void release(); virtual void x(); };
struct Provider_272df0 { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual unsigned get(unsigned); virtual unsigned convert(unsigned); };
struct Callback_272df0 { virtual unsigned run(unsigned,unsigned); };
typedef unsigned (Callback_272df0::*CallbackMethod)(unsigned,unsigned);
struct CallbackTable { void* run; };
struct DriveSlots_272df0 { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual unsigned vfunc_4(unsigned); };
extern "C" CoreThread* __cdecl FUN_0026dbb0();
namespace core { struct Drive_272df0 : CoreDrive { void vfunc_3(); void FUN_00272a40(unsigned); }; }
void core::Drive_272df0::vfunc_3() {
 CoreThread* token=FUN_0026dbb0();
 Lock_272df0* lock=(Lock_272df0*)&vftableMutable;
 lock->acquire();
 Node** link=(Node**)&requests; Node* previous=0; Node* temporary;
 while (*link) {
  if ((*link)->FUN_00273680(token)) { Node* node=*link; *link=node->next; lock->release(); node->process(); lock->acquire(); node->destroy(1); }
  else { previous=*link; temporary=previous->next; link=&temporary; }
 }
 lastRequest=previous;
 if (active==1 && callback) {
  if (!busy) {
   busy=1; lock->release();
   CallbackTable* table=*(CallbackTable**)callback;
   Provider_272df0* p=(Provider_272df0*)request;
   unsigned value=p->get(argument);
   value=p->convert(value);
   unsigned kind=((DriveSlots_272df0*)this)->vfunc_4(value);
   union { void* address; CallbackMethod method; } entry; entry.address=table->run;
   unsigned result=(((Callback_272df0*)callback)->*entry.method)((unsigned)error,kind);
   FUN_00272a40(result);
   busy=0;
  } else lock->release();
 } else lock->release();
}
