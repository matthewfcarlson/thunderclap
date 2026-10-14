// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 6/6)
// CHand2HandAgent::vfunc_13 @ 0x000ff7a0
struct RandomState_ff7a0 { unsigned first, second; };
extern RandomState_ff7a0* FUN_000964d0();
struct EventName { void FUN_0027b040(const char*); };
struct Recipient_ff7a0 { char pad[0x2098]; EventName event; char pad2[7]; unsigned char active; };
struct CHand2HandAgent {
 char pad[0x84]; unsigned state; char pad2[0xc]; float x,y,z; char pad3[0x1c]; float dx,dy,dz;
 bool vfunc_13(Recipient_ff7a0*);
};
bool CHand2HandAgent::vfunc_13(Recipient_ff7a0* recipient) {
 RandomState_ff7a0* random = FUN_000964d0();
 random->first = (random->first & 0xffffu)*0x9069u + (random->first >> 16);
 random->second = (random->second & 0xffffu)*0x4650u + (random->second >> 16);
 float dot = dz*z + dy*y + dx*x;
 double cross = (double)z*dx - (double)dz*x;
 if (dot > 0.7f || dot > -0.7f) {
  if (cross < 0.0f) recipient->event.FUN_0027b040("evade_e");
  else recipient->event.FUN_0027b040("evade_w");
  recipient->active = 1;
 }
 state = 0;
 return true;
}