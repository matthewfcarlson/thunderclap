// STATUS: equivalent (tools/equiv.py level 3: 95 inputs, branch coverage 18/18)
// FUN_0028ceb0 @ 0x0028ceb0
#include "gen/owners.h"
struct Stream {  };
struct Owner_28ceb0 { char pad[0x284]; Stream* stream; };
struct Pool_28ceb0 {  };
struct BoolChannel_28ceb0 { char pad0[8]; unsigned value; char pad1[8]; unsigned short* entries; unsigned* bits; BoolChannel_28ceb0* FUN_0028c370(unsigned, Pool_28ceb0*); };
extern "C" void* __cdecl FUN_0008d690(unsigned);
BoolChannel_28ceb0* __stdcall FUN_0028ceb0(Owner_28ceb0* owner, unsigned unused, Pool_28ceb0* pool) {
 unsigned count; unsigned value;
 ((owners::X_2647e0 *)(owner->stream))->FUN_002647e0((hulk_intptr)(&count), (hulk_intptr)1, 4, (hulk_intptr)1);
 ((owners::X_2647e0 *)(owner->stream))->FUN_002647e0((hulk_intptr)(&value), (hulk_intptr)1, 4, (hulk_intptr)1);
 ((owners::X_2647e0 *)(owner->stream))->FUN_002647e0((hulk_intptr)(&count), (hulk_intptr)1, 2, (hulk_intptr)1);
 bool active = (unsigned short)count == 1;
 ((owners::X_2647e0 *)(owner->stream))->FUN_002647e0((hulk_intptr)(&count), (hulk_intptr)1, 4, (hulk_intptr)1);
 BoolChannel_28ceb0* storage = (BoolChannel_28ceb0*)(pool ? ((void *)((owners::C_2888c0 *)pool)->FUN_002888c0((int)sizeof(BoolChannel_28ceb0), 7)) : FUN_0008d690((int)sizeof(BoolChannel_28ceb0)));
 BoolChannel_28ceb0* result = storage ? storage->FUN_0028c370(count+1,pool) : 0;
 unsigned short* destination = result->entries + 1;
 result->value = value;
 ((owners::X_2647e0 *)(owner->stream))->FUN_002647e0((hulk_intptr)destination, (hulk_intptr)count, 2, (hulk_intptr)1);
 result->entries[0] = 0xffff;
 unsigned total = count+1;
 for(unsigned i=0;i<total;++i) {
 if(active) result->bits[i/32] |= 1u << (i%32);
 active = !active;
 }
 return result;
}