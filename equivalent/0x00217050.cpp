// STATUS: equivalent (tools/equiv.py level 3: 2927 inputs, branch coverage 6/6)
// FUN_00217050 @ 0x00217050
struct State_217050;
struct Node { Node* next; unsigned char pad4; unsigned char flags; char pad6[10]; State_217050* state; };
struct State_217050 { char pad0[20]; unsigned int flags; char pad18[16]; unsigned int active; unsigned int pending; unsigned int queued; Node* list; unsigned int done; };
void __cdecl FUN_00216ff0(State_217050*);
void __cdecl FUN_002164b0(State_217050*,Node*);
// equiv-conv: FUN_00216ac0 eax stack
void __cdecl FUN_00216ac0(int,State_217050*);
void __cdecl FUN_002165c0(Node*,int);
// equiv-conv: FUN_00216c40 eax
void __cdecl FUN_00216c40(unsigned int);
// equiv-conv: FUN_00217050 eax
void __cdecl FUN_00217050(Node* node) {
 State_217050* state=node->state;
 FUN_00216ff0(state);
 state->active=state->queued;
 state->queued=0;
 if(node->flags & 3) FUN_002164b0(state,node);
 FUN_00216ac0(0x7fffffff,state);
 state->active=state->pending;
 state->pending=0;
 FUN_00216ac0(0x7fffffff,state);
 FUN_002165c0(node,0);
 for(Node* p=state->list;p;p=p->next) {
 p->flags=(p->flags & 0xf8) | (unsigned char)state->flags;
 FUN_002164b0(state,p);
 }
 FUN_00216ac0(0x7fffffff,state);
 FUN_00216c40(state->queued);
 state->flags ^= 3;
 state->done=1;
}