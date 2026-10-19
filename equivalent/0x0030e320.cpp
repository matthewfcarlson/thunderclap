// STATUS: equivalent (tools/equiv.py level 3: 12492 inputs, branch coverage 10/10)
// physics::CollisionAnalyser::vfunc_4 @ 0x0030e320
struct PairKey { unsigned first, firstData, second, secondData; };
struct Entry_30e320 {
 char pad[0x84]; unsigned char active;
 void FUN_0031a380(unsigned, unsigned, unsigned, unsigned, unsigned);
 void FUN_0030d760(unsigned, void*, unsigned, unsigned, unsigned);
 void FUN_0030d7c0(unsigned, void*, unsigned, unsigned);
};
struct Link_30e320 { void FUN_0030d850(unsigned, unsigned, unsigned, unsigned, Entry_30e320*); };
namespace physics {
struct CollisionAnalyser {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
 virtual int vfunc_4(unsigned a, unsigned ad, unsigned b, unsigned bd, unsigned x, unsigned y, unsigned z);
 char pad04[8]; unsigned context;
 char pad10[0x44]; unsigned state[3]; unsigned mode60, mode64, mode68;
 Entry_30e320* FUN_0030d900(PairKey*);
 Entry_30e320* FUN_0030df50();
 Link_30e320* FUN_0030e280();
};
int CollisionAnalyser::vfunc_4(unsigned a, unsigned ad, unsigned b, unsigned bd, unsigned x, unsigned y, unsigned z) {
 if (!mode68 || a == b) return 1;
 PairKey key;
 if (a < b) { key.first=a; key.firstData=ad; key.second=b; key.secondData=bd; }
 else { key.first=b; key.firstData=bd; key.second=a; key.secondData=ad; }
 Entry_30e320* entry=FUN_0030d900(&key);
 if (!entry) {
 entry=FUN_0030df50();
 unsigned flags=(((mode64 << 8) | mode60) << 8) | mode68;
 entry->FUN_0031a380(a,ad,b,bd,flags);
 Link_30e320* link=FUN_0030e280();
 link->FUN_0030d850(a, ad, b, bd, entry);
 }
 if (entry->active) entry->FUN_0030d760(x,state,y,z,context);
 else entry->FUN_0030d7c0(x,state,y,z);
 return 0;
}
}
