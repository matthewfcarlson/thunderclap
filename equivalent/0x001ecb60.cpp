// STATUS: equivalent (tools/equiv.py level 3: 20008 inputs, branch coverage 18/18)
// FUN_001ecb60 @ 0x001ecb60
// cl-flags: /GS
struct ImpactInfo { char pad[0x14]; int type; };
struct Source_1ecb60 { char pad[0x11c]; ImpactInfo* info; };
struct State_1ecb60 { int FUN_001d5040(); };
struct Recipient_1ecb60 { char pad[0xec]; State_1ecb60* state; };
struct Effects_1ecb60 {
 void FUN_001ec980(Source_1ecb60*, const char*);
 void FUN_001ebd80(Recipient_1ecb60*, const char*, float, int);
 void FUN_001ecb60(Source_1ecb60*, Recipient_1ecb60*, const char*);
};
void Effects_1ecb60::FUN_001ecb60(Source_1ecb60* source, Recipient_1ecb60* recipient, const char* name) {
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
}
