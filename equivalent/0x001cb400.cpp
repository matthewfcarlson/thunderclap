// STATUS: equivalent (tools/equiv.py level 3: 3066 inputs, branch coverage 21/25, incomplete)
// FUN_001cb400 @ 0x001cb400
struct Item {
 char pad0[4]; unsigned int kind; char pad8[0x28]; int value30; int value34;
 int FUN_001c96e0(int);
 void FUN_001c9700(int,int);
};
struct Lookup { int FUN_00059ba0(int); };
struct Owner { char pad[0x44]; Lookup* lookup; };
struct Handler { char pad[4]; Owner* owner; bool check(Item*); };
bool Handler::check(Item* item) {
 switch(item->kind) {
 case 4: case 15: case 16: case 17: case 18: case 21: case 29: case 30:
 { int value = item->FUN_001c96e0(2); return owner->lookup->FUN_00059ba0(value)==0; }
 case 20: case 23:
 { int value = item->FUN_001c96e0(2); if(owner->lookup->FUN_00059ba0(value)==0) { item->value34=0; item->value30=0; item->FUN_001c9700(2,0); } break; }
 }
 return false;
}