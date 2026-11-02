// STATUS: equivalent (tools/equiv.py level 3: 2927 inputs, branch coverage 6/6)
// FUN_00217050 @ 0x00217050
#include "compat/ptr.h"
struct State_217050;
struct Node { Node* next; unsigned char pad4; unsigned char flags; char pad6[10]; State_217050* state; };
struct State_217050 { char pad0[20]; unsigned int flags; char pad18[16]; unsigned int active; unsigned int pending; unsigned int queued; Node* list; unsigned int done; };
extern "C" void __cdecl FUN_00216ff0(void *);
extern "C" void __cdecl FUN_002164b0(void *, void *);
// equiv-conv: FUN_00216ac0 eax stack
extern "C" int __cdecl FUN_00216ac0(int, void *);
extern "C" unsigned int __cdecl FUN_002165c0(void *, int);
// equiv-conv: FUN_00216c40 eax
extern "C" void __cdecl FUN_00216c40(void *);
// equiv-conv: FUN_00217050 eax
extern "C" void __cdecl FUN_00217050(void * node) {
 State_217050* state=((Node *)node)->state;
 FUN_00216ff0((State_217050 *)state);
 state->active=state->queued;
 state->queued=0;
 if(((Node *)node)->flags & 3) FUN_002164b0((State_217050 *)state,(Node *)((Node *)node));
 FUN_00216ac0(0x7fffffff,(State_217050 *)state);
 state->active=state->pending;
 state->pending=0;
 FUN_00216ac0(0x7fffffff,(State_217050 *)state);
 FUN_002165c0((Node *)((Node *)node),0);
 for(Node* p=state->list;p;p=p->next) {
 p->flags=(p->flags & 0xf8) | (unsigned char)state->flags;
 FUN_002164b0((State_217050 *)state,(Node *)p);
 }
 FUN_00216ac0(0x7fffffff,(State_217050 *)state);
 FUN_00216c40((void *)(hulk_uintptr)(unsigned int)(state->queued));
 state->flags ^= 3;
 state->done=1;
}