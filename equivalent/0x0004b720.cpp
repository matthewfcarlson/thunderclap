// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 21/22, incomplete)
// CAxisDoubleTapCondition::vfunc_9 @ 0x0004b720
struct AxisEvent { char pad[0x14]; int value; char pad2[0x14]; int kind; int axis; float position; };
extern float __cdecl FUN_00224fc0(int axis, int value);
extern bool __cdecl FUN_00018960(float a, float b, float tolerance);
struct CAxisDoubleTapCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual bool vfunc_9(int unused, AxisEvent* event);
 char pad[12]; unsigned comparison; float threshold; float lower; float upper;
};
bool CAxisDoubleTapCondition::vfunc_9(int unused, AxisEvent* event) {
 if(event->kind != 1) return false;
 if(lower < upper) {
 if(event->position < lower || event->position > upper) return false;
 }
 float value = FUN_00224fc0(event->axis, event->value);
 float limit = threshold * 0.5f;
 union { float f; unsigned u; } magnitude;
 magnitude.f=value; magnitude.u &= 0x7fffffff;
 switch(comparison) {
 case 0: return magnitude.f < limit;
 case 1: return magnitude.f <= limit;
 case 2: return FUN_00018960(magnitude.f, limit, 0.00001f);
 case 3: return !FUN_00018960(magnitude.f, limit, 0.00001f);
 case 4: return magnitude.f >= limit;
 case 5: return magnitude.f > limit;
 default: return false;
 }
}
