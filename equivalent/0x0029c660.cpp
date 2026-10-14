// STATUS: equivalent (tools/equiv.py level 3: 69 inputs, branch coverage 12/12)
// FUN_0029c660 @ 0x0029c660
struct Entry { int first; int pad4; int second; char pad12[12]; int third; int pad28; };
struct Owner { char pad[20]; int count; void FUN_002a0fc0(int index,int zero); };
struct Target { Owner* owner; Entry* entries; int count; void reset(); };
void Target::reset() { for(int i=count-1;i>=0;--i) { entries[i].first=0; entries[i].second=0; entries[i].third=0; } for(int j=owner->count-1;j>=0;--j) owner->FUN_002a0fc0(j,0); }
