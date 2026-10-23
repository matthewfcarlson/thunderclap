// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// fight::ScriptReader::vfunc_16 @ 0x0023b140
#include "gen/fight.h"

struct Pair_23b140 {
 unsigned int low, high;
 void FUN_0027af70(Pair_23b140*);
 void FUN_0027b040(int);
};
namespace fight {
struct ScriptReader_nv_23b140 {
    void FUN_0023ab40();
    void FUN_0023a6b0();
};

}
__int64 fight::ScriptReader::vfunc_16(int __p0, int __p1) { unsigned int low = (unsigned int)__p0; unsigned int high = (unsigned int)__p1;

 ++this->f_10;
 ((ScriptReader_nv_23b140*)this)->FUN_0023ab40();
 int level = this->f_10;
 if (level >= 64) return (__int64)(0);
 if (((*(Pair_23b140 *)&this->f_120).low | (*(Pair_23b140 *)&this->f_120).high) != 0 && this->f_128 >= (&this->f_10)[level] &&
     ((low | high) == 0 || ((*(Pair_23b140 *)&this->f_120).low == low && (*(Pair_23b140 *)&this->f_120).high == high))) {
   (*(Pair_23b140 *)&this->f_118).FUN_0027af70(&(*(Pair_23b140 *)&this->f_120));
   (&this->f_10)[this->f_10 + 1] = this->f_128;
   (*(Pair_23b140 *)&this->f_120).FUN_0027b040(0);
   this->f_128 = 0;
   ((ScriptReader_nv_23b140*)this)->FUN_0023a6b0();
   return (__int64)(((unsigned __int64)(*(Pair_23b140 *)&this->f_118).high << 32) | (*(Pair_23b140 *)&this->f_118).low);
 }
 (&this->f_10)[level + 1] = (&this->f_10)[level];
 return (__int64)(0);
}
