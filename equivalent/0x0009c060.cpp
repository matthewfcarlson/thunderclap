// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 14/14)
// FUN_0009c060 @ 0x0009c060
struct Node { void FUN_000361c0(int); void FUN_00036140(int); };
struct Details { char pad[0x124]; Node* node; };
struct State { char pad[8]; unsigned char active; };
struct Input { char pad0[4]; State* state; char pad1[0x18]; Details* details; };
struct Worker { char pad[0x2cc]; unsigned char active; void FUN_000ac9c0(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned); };
struct Result { void FUN_00086100(); };
struct Lookup { Result* FUN_00086320(unsigned); };
struct Helper { void FUN_00098480(Input*); };
struct Object {
 char pad0[4]; unsigned flags; char pad1[4]; Lookup* lookup; unsigned current; unsigned previous; unsigned char disabled; char pad2[0xa3]; Helper* helper; char pad3[4]; Worker* worker;
 void FUN_0009a1e0(Input*);
 void FUN_000991b0(Input*, unsigned, Worker*, int, int);
 void target(Input*, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
};
void Object::target(Input* input, unsigned a2, unsigned a3, unsigned a4, unsigned a5, unsigned a6, unsigned a7, unsigned a8) {
 if (disabled || (flags & 0x10) || (flags & 0x40)) return;
 if (flags & 2) FUN_0009a1e0(input);
 if (flags & 0x5e) return;
 if (flags & 0x20) helper->FUN_00098480(input);
 previous = current;
 flags &= ~0x20u;
 worker->FUN_000ac9c0(a2,a3,a4,a5,a6,a7);
 lookup->FUN_00086320(a8)->FUN_00086100();
 input->state->active = worker->active;
 Node* node = input->details->node;
 if (node) { node->FUN_000361c0(1); node->FUN_00036140(1); }
 flags |= 0x10;
 FUN_000991b0(input,current,worker,0,0);
}
