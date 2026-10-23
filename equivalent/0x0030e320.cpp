// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 10/10)
// physics::CollisionAnalyser::vfunc_4 @ 0x0030e320
#include "gen/physics.h"

struct PairKey { unsigned first, firstData, second, secondData; };
struct Entry_30e320 {
 char pad[0x84]; unsigned char active;
 void FUN_0031a380(unsigned, unsigned, unsigned, unsigned, unsigned);
 void FUN_0030d760(unsigned, void*, unsigned, unsigned, unsigned);
 void FUN_0030d7c0(unsigned, void*, unsigned, unsigned);
};
struct Link_30e320 { void FUN_0030d850(unsigned, unsigned, unsigned, unsigned, Entry_30e320*); };
namespace physics {
struct CollisionAnalyser_nv_30e320 {
    Entry_30e320* FUN_0030d900(PairKey*);
    Entry_30e320* FUN_0030df50();
    Link_30e320* FUN_0030e280();
};

}
int physics::CollisionAnalyser::vfunc_4(int __p0, int __p1, int __p2, int __p3, int __p4, int __p5, int __p6) { unsigned int a = (unsigned int)__p0; unsigned int ad = (unsigned int)__p1; unsigned int b = (unsigned int)__p2; unsigned int bd = (unsigned int)__p3; unsigned int x = (unsigned int)__p4; unsigned int y = (unsigned int)__p5; unsigned int z = (unsigned int)__p6;

 if (!this->f_68 || a == b) return 1;
 PairKey key;
 if (a < b) { key.first=a; key.firstData=ad; key.second=b; key.secondData=bd; }
 else { key.first=b; key.firstData=bd; key.second=a; key.secondData=ad; }
 Entry_30e320* entry=((CollisionAnalyser_nv_30e320*)this)->FUN_0030d900(&key);
 if (!entry) {
 entry=((CollisionAnalyser_nv_30e320*)this)->FUN_0030df50();
 unsigned flags=(((this->f_64 << 8) | this->f_60) << 8) | this->f_68;
 entry->FUN_0031a380(a,ad,b,bd,flags);
 Link_30e320* link=((CollisionAnalyser_nv_30e320*)this)->FUN_0030e280();
 link->FUN_0030d850(a, ad, b, bd, entry);
 }
 if (entry->active) entry->FUN_0030d760(x,(*(unsigned int (*)[3])&this->f_54),y,z,this->f_0c);
 else entry->FUN_0030d7c0(x,(*(unsigned int (*)[3])&this->f_54),y,z);
 return 0;
}
