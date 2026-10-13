// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 18/18)
// FUN_001ecb60 @ 0x001ecb60
extern unsigned int DAT_004d9968;
// equiv-conv: __security_check_cookie ecx
void __security_check_cookie(unsigned int);
struct ImpactInfo { char pad[0x14]; int type; };
struct Source { char pad[0x11c]; ImpactInfo* info; };
struct State { int FUN_001d5040(); };
struct Recipient { char pad[0xec]; State* state; };
struct Effects {
 void FUN_001ec980(Source*, const char*);
 void FUN_001ebd80(Recipient*, const char*, float, int);
 void FUN_001ecb60(Source*, Recipient*, const char*);
};
void Effects::FUN_001ecb60(Source* source, Recipient* recipient, const char* name) {
 unsigned int cookie = DAT_004d9968;
 if (source && source->info && recipient && recipient->state && recipient->state->FUN_001d5040()) {
 FUN_001ec980(source, name);
 char buffer[16];
 const char* chosen = "impact_sml";
 if (source->info->type == 2 || source->info->type == 1) {
  const char* whiff = "whiff";
  int i;
  for (i=0; i<6; ++i) if (name[i] != whiff[i]) break;
  chosen = i == 6 ? name : "impact_big";
 }
 int j=0;
 do { buffer[j] = chosen[j]; } while (chosen[j++]);
 FUN_001ebd80(recipient, buffer, 100.0f, 0);
 }
 __security_check_cookie(cookie);
}
