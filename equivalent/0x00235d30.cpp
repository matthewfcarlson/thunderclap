// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// fight::FightNodeTimeCondition::vfunc_6 @ 0x00235d30
struct TimeData { char pad[28]; float time; };
extern bool __cdecl FUN_00018960(float, float, float);
namespace fight {
struct FightNodeTimeCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(unsigned a, unsigned b, unsigned c); virtual TimeData* FUN_00344f51(unsigned);
 char pad[8]; unsigned comparison; float threshold;
};
bool FightNodeTimeCondition::vfunc_6(unsigned a, unsigned b, unsigned c) {
 TimeData* data = FUN_00344f51(b);
 if (!data) return false;
 float time = data->time;
 switch (comparison) {
 case 0: return time < threshold;
 case 1: return time <= threshold;
 case 2: return FUN_00018960(time, threshold, 0.00001f);
 case 3: return !FUN_00018960(time, threshold, 0.00001f);
 case 4: return time >= threshold;
 case 5: return time > threshold;
 default: return false;
 }
}
}