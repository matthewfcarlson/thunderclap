// STATUS: equivalent (tools/equiv.py level 3: 19992 inputs, branch coverage 14/14)
// FUN_0009c060 @ 0x0009c060
struct Node { void FUN_000361c0(int); void FUN_00036140(int); };
struct Details_9c060 { char pad[0x124]; Node* node; };
struct State_9c060 { char pad[8]; unsigned char active; };
struct Input_9c060 { char pad0[4]; State_9c060* state; char pad1[0x18]; Details_9c060* details; };
struct Worker_9c060 { char pad[0x2cc]; unsigned char active; void FUN_000ac9c0(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned); };
struct Result_9c060 { void FUN_00086100(unsigned); };
struct Lookup_9c060 { Result_9c060* FUN_00086320(); };
struct Helper_9c060 { void FUN_00098480(Input_9c060*); };
struct Object {
 char pad0[4]; unsigned flags; char pad1[4]; Lookup_9c060* lookup; unsigned current; unsigned previous; unsigned char disabled; char pad2[0xa3]; Helper_9c060* helper; char pad3[4]; Worker_9c060* worker;
 void FUN_0009a1e0(Input_9c060*);
 void FUN_000991b0(Input_9c060*, unsigned, Worker_9c060*, int, int);
 void target(Input_9c060*, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
};
void Object::target(Input_9c060* input, unsigned a2, unsigned a3, unsigned a4, unsigned a5, unsigned a6, unsigned a7, unsigned a8) {
 if (disabled || (flags & 0x10) || (flags & 0x40)) return;
 if (flags & 2) FUN_0009a1e0(input);
 if (flags & 0x5e) return;
 if (flags & 0x20) helper->FUN_00098480(input);
 previous = current;
 flags &= ~0x20u;
 worker->FUN_000ac9c0(a2,a3,a4,a5,a6,a7);
 lookup->FUN_00086320()->FUN_00086100(a8);
 input->state->active = worker->active;
 Node* node = input->details->node;
 if (node) { node->FUN_000361c0(1); node->FUN_00036140(1); }
 flags |= 0x10;
 FUN_000991b0(input,current,worker,0,0);
}
