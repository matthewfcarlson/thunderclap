// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// fight::ScriptReader::vfunc_16 @ 0x0023b140
struct Pair {
 unsigned int low, high;
 void FUN_0027af70(Pair*);
 void FUN_0027b040(int);
};
namespace fight {
struct ScriptReader {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
 virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
 virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
 virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
 virtual unsigned __int64 vfunc_16(unsigned int low, unsigned int high);
 char pad[12];
 int depth;
 int limits[65];
 Pair result;
 Pair pending;
 int pendingLimit;
 void FUN_0023ab40();
 void FUN_0023a6b0();
};
unsigned __int64 ScriptReader::vfunc_16(unsigned int low, unsigned int high) {
 ++depth;
 FUN_0023ab40();
 int level = depth;
 if (level >= 64) return 0;
 if ((pending.low | pending.high) != 0 && pendingLimit >= (&depth)[level] &&
     ((low | high) == 0 || (pending.low == low && pending.high == high))) {
   result.FUN_0027af70(&pending);
   (&depth)[depth + 1] = pendingLimit;
   pending.FUN_0027b040(0);
   pendingLimit = 0;
   FUN_0023a6b0();
   return ((unsigned __int64)result.high << 32) | result.low;
 }
 (&depth)[level + 1] = (&depth)[level];
 return 0;
}
}