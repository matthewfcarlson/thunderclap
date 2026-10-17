// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// movie::BinkCallback::vfunc_2_adj8 @ 0x00335150
namespace movie { struct BinkCallback { char pad[8]; void vfunc_0(); void vfunc_2_adj8(); }; void BinkCallback::vfunc_2_adj8() { ((BinkCallback*)((char*)this - 8))->vfunc_0(); } }