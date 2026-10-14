// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001c9aa0 @ 0x001c9aa0
struct Actor { const char* FUN_00036d00(); };
struct ActorTable { Actor* FUN_00059c10(int id); };
struct World { char pad[0x44]; ActorTable* actors; };
extern World* DAT_004dd700;
struct Writer {
 bool FUN_001d2e80();
 void FUN_001d1dd0(const char* key, int value);
 void FUN_001d1d90(const char* key, int value);
 void FUN_001d1d50(const char* key, const char* value);
 void FUN_001d1d10();
};
Writer* FUN_001d4c90();
struct ChargeEvent {
 char pad[0x10];
 int actorId; int chargeType; int charge;
 bool Write();
};
bool ChargeEvent::Write() {
 Writer* w = FUN_001d4c90();
 if (w && w->FUN_001d2e80()) {
  w->FUN_001d1dd0("charge_type", chargeType);
  w->FUN_001d1d90("charge", charge);
  if (DAT_004dd700) {
   Actor* a = DAT_004dd700->actors->FUN_00059c10(actorId);
   const char* name = a ? a->FUN_00036d00() : "UNKNOWN";
   w->FUN_001d1d50("actor", name);
   w->FUN_001d1d10();
   return true;
  }
  w->FUN_001d1d10();
 }
 return false;
}
