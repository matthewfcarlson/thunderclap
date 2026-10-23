// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 0/0)
// CRangedAgent::vfunc_9 @ 0x00107300
#include "gen/global.h"

struct RandomState_107300 { unsigned int first, second; };
struct CRangedAgent_nv_107300 {
    RandomState_107300* FUN_000964d0();
    void FUN_00107140();
};

void CRangedAgent::vfunc_9() {
 RandomState_107300* r = ((CRangedAgent_nv_107300*)this)->FUN_000964d0();
 ((CRangedAgent_nv_107300*)this)->FUN_00107140();
 (*(unsigned int *)&this->f_08)=0; (*(unsigned char *)&this->f_6c)=0;
 r->first = (r->first & 0xffffu)*0x9069u + (r->first >> 16);
 r->second = (r->second & 0xffffu)*0x4650u + (r->second >> 16);
 union { unsigned int bits; float value; } random;
 random.bits = (((r->first << 16) + (r->second & 0xffffu)) & 0x7fffffu) | 0x3f800000u;
 this->f_70 = -((random.value-1.0f)*this->f_98);
 r->first = (r->first & 0xffffu)*0x9069u + (r->first >> 16);
 r->second = (r->second & 0xffffu)*0x4650u + (r->second >> 16);
 random.bits = (((r->first << 16) + (r->second & 0xffffu)) & 0x7fffffu) | 0x3f800000u;
 (*(unsigned int *)&this->f_78)=0; this->f_7c=1.0f; (*(unsigned int *)&this->f_a0)=0; this->f_a4=-45.0f; (*(unsigned char *)&this->f_a8)=0;
 this->f_74=(random.value-1.0f)*this->f_9c;
 (*(unsigned int *)&this->f_68)=0; (*(unsigned int *)&this->f_64)=0; (*(unsigned int *)&this->f_60)=0; (*(unsigned int *)&this->f_ac)=0;
}
