// STATUS: equivalent (tools/equiv.py level 3: 3026 inputs, branch coverage 32/32)
// FUN_001d7d50 @ 0x001d7d50
struct Gate { bool FUN_000242d0(int); }; struct Mode { bool FUN_000997a0(); }; struct Globals { char p[8]; Mode* mode; char q[20]; Gate* gate; }; extern Globals* DAT_004dd700;
struct State { char p[8]; int id; int type; };
struct Resource { virtual void dummy(); virtual void release(); void FUN_0001b4f0(); };
struct Flag { char p[24]; unsigned char active; }; struct Link { char p[32]; Flag* flag; }; struct Related { char p[116]; Link* link; };
struct Counter { int FUN_001d5c70(int); };
struct Object { char a[64]; int current; char b[168]; Counter* counter; char c[12]; int pending; char d[8]; int count; char e[4]; unsigned char enabled; char f[3]; State* state; char g[28]; Resource* resource;
 void FUN_0027d4f0(int); Related* FUN_001d72e0(); bool target(); };
bool Object::target() {
 if (state && state->type == 1 && DAT_004dd700->gate->FUN_000242d0(state->id) && !DAT_004dd700->mode->FUN_000997a0()) return false;
 if (pending || !enabled || count > 0) return false;
 int previous = current;
 FUN_0027d4f0(13);
 int next = current;
 count = counter->FUN_001d5c70(next);
 enabled = count > 0;
 if (next == -1) return false;
 if (next != previous) {
 Resource* saved = resource;
 if (saved && FUN_001d72e0() && FUN_001d72e0()->link && !FUN_001d72e0()->link->flag->active) {
 saved->FUN_0001b4f0();
 if (resource) resource->release();
 resource = 0;
 }
 if (state) FUN_0027d4f0(5);
 }
 return true;
}