// STATUS: equivalent (tools/equiv.py level 3: 3040 inputs, branch coverage 17/18, incomplete)
// CGrappleOpportunityTrack::vfunc_10 @ 0x0005ae00
struct Context { char pad[8]; unsigned value; };
struct Owner_5ae00;
struct Link_5ae00 { char pad[16]; unsigned* data; };
struct State_5ae00 { char pad[0x330]; Link_5ae00* fallback; Link_5ae00* primary; };
struct Intermediate_5ae00 { State_5ae00* FUN_00059a30(); };
struct Owner_5ae00 { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual Context* s4(); Intermediate_5ae00* FUN_000592a0(); };
struct CGrappleOpportunityTrack;
struct Result_5ae00 { unsigned FUN_00237470(unsigned,CGrappleOpportunityTrack*,float,float,unsigned,unsigned,void*,unsigned,Context*); };
Result_5ae00* __cdecl FUN_0008d690(unsigned);
struct CGrappleOpportunityTrack {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual unsigned vfunc_8(unsigned,Owner_5ae00*); virtual void vfunc_9(); virtual unsigned vfunc_10(unsigned,unsigned,Owner_5ae00*); virtual void vfunc_11();
 char pad[8]; float start; float first; float second; unsigned field18; char pad1c[8]; unsigned field24; char payload[4];
};
unsigned CGrappleOpportunityTrack::vfunc_10(unsigned a,unsigned b,Owner_5ae00* owner) {
 if (!owner) return 0;
 Intermediate_5ae00* i=owner->FUN_000592a0(); if(!i) return 0;
 State_5ae00* state=i->FUN_00059a30(); if(!state) return 0;
 Link_5ae00* link=state->primary; if(!link) link=state->fallback; if(!link) return 0;
 float d1=first-start; float d2=second-start;
 if(d2<0.0f && second>=0.0f) d2=0.0f;
 Context* context=owner->s4(); context->value=*link->data;
 Result_5ae00* result=FUN_0008d690(0x50); if(!result) return 0;
 unsigned saved=field18;
 unsigned v=vfunc_8(b,owner);
 return result->FUN_00237470(a,this,d1,d2,saved,field24,payload,v,context);
}