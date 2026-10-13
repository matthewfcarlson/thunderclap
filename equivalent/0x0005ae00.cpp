// STATUS: equivalent (tools/equiv.py level 3: 3014 inputs, branch coverage 17/18, incomplete)
// CGrappleOpportunityTrack::vfunc_10 @ 0x0005ae00
struct Context { char pad[8]; unsigned value; };
struct Owner;
struct Link { char pad[16]; unsigned* data; };
struct State { char pad[0x330]; Link* fallback; Link* primary; };
struct Intermediate { State* FUN_00059a30(); };
struct Owner { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual Context* s4(); Intermediate* FUN_000592a0(); };
struct CGrappleOpportunityTrack;
struct Result { unsigned FUN_00237470(unsigned,CGrappleOpportunityTrack*,float,float,unsigned,unsigned,void*,unsigned,Context*); };
Result* __cdecl FUN_0008d690(unsigned);
struct CGrappleOpportunityTrack {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual unsigned vfunc_8(unsigned,Owner*); virtual void vfunc_9(); virtual unsigned vfunc_10(unsigned,unsigned,Owner*); virtual void vfunc_11();
 char pad[8]; float start; float first; float second; unsigned field18; char pad1c[8]; unsigned field24; char payload[4];
};
unsigned CGrappleOpportunityTrack::vfunc_10(unsigned a,unsigned b,Owner* owner) {
 if (!owner) return 0;
 Intermediate* i=owner->FUN_000592a0(); if(!i) return 0;
 State* state=i->FUN_00059a30(); if(!state) return 0;
 Link* link=state->primary; if(!link) link=state->fallback; if(!link) return 0;
 float d1=first-start; float d2=second-start;
 if(d2<0.0f && second>=0.0f) d2=0.0f;
 Context* context=owner->s4(); context->value=*link->data;
 Result* result=FUN_0008d690(0x50); if(!result) return 0;
 unsigned saved=field18;
 unsigned v=vfunc_8(b,owner);
 return result->FUN_00237470(a,this,d1,d2,saved,field24,payload,v,context);
}