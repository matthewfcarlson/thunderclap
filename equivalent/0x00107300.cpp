// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 0/0)
// CRangedAgent::vfunc_9 @ 0x00107300
struct RandomState { unsigned int first, second; };
struct CRangedAgent {
 char pad0[8]; unsigned int state; char padC[0x60-0xc];
 unsigned int field60, field64, field68; unsigned char flag6c; char pad6d[3];
 float timer70, timer74; unsigned int field78; float field7c;
 char pad80[0x18]; float range98, range9c; unsigned int fielda0; float fielda4; unsigned char flaga8; char pada9[3]; unsigned int fieldac;
 RandomState* FUN_000964d0();
 void FUN_00107140();
 void vfunc_9();
};
void CRangedAgent::vfunc_9() {
 RandomState* r = FUN_000964d0();
 FUN_00107140();
 state=0; flag6c=0;
 r->first = (r->first & 0xffffu)*0x9069u + (r->first >> 16);
 r->second = (r->second & 0xffffu)*0x4650u + (r->second >> 16);
 union { unsigned int bits; float value; } random;
 random.bits = (((r->first << 16) + (r->second & 0xffffu)) & 0x7fffffu) | 0x3f800000u;
 timer70 = -((random.value-1.0f)*range98);
 r->first = (r->first & 0xffffu)*0x9069u + (r->first >> 16);
 r->second = (r->second & 0xffffu)*0x4650u + (r->second >> 16);
 random.bits = (((r->first << 16) + (r->second & 0xffffu)) & 0x7fffffu) | 0x3f800000u;
 field78=0; field7c=1.0f; fielda0=0; fielda4=-45.0f; flaga8=0;
 timer74=(random.value-1.0f)*range9c;
 field68=0; field64=0; field60=0; fieldac=0;
}
