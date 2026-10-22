// STATUS: equivalent (tools/equiv.py level 3: 95 inputs, branch coverage 18/18)
// FUN_0028ceb0 @ 0x0028ceb0
struct Stream { void FUN_002647e0(void*, unsigned, unsigned, unsigned); };
struct Owner_28ceb0 { char pad[0x284]; Stream* stream; };
struct Pool_28ceb0 { void* FUN_002888c0(unsigned, unsigned); };
struct BoolChannel_28ceb0 { char pad0[8]; unsigned value; char pad1[8]; unsigned short* entries; unsigned* bits; BoolChannel_28ceb0* FUN_0028c370(unsigned, Pool_28ceb0*); };
void* __cdecl FUN_0008d690(unsigned);
BoolChannel_28ceb0* __stdcall FUN_0028ceb0(Owner_28ceb0* owner, unsigned unused, Pool_28ceb0* pool) {
 unsigned count; unsigned value;
 owner->stream->FUN_002647e0(&count,1,4,1);
 owner->stream->FUN_002647e0(&value,1,4,1);
 owner->stream->FUN_002647e0(&count,1,2,1);
 bool active = (unsigned short)count == 1;
 owner->stream->FUN_002647e0(&count,1,4,1);
 BoolChannel_28ceb0* storage = (BoolChannel_28ceb0*)(pool ? pool->FUN_002888c0(0x1c,7) : FUN_0008d690(0x1c));
 BoolChannel_28ceb0* result = storage ? storage->FUN_0028c370(count+1,pool) : 0;
 unsigned short* destination = result->entries + 1;
 result->value = value;
 owner->stream->FUN_002647e0(destination,count,2,1);
 result->entries[0] = 0xffff;
 unsigned total = count+1;
 for(unsigned i=0;i<total;++i) {
 if(active) result->bits[i/32] |= 1u << (i%32);
 active = !active;
 }
 return result;
}