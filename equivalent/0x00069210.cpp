// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 11/12, incomplete)
// FUN_00069210 @ 0x00069210
struct Curve_69210 {
 char pad0[0x14];
 float startScale;
 float endScale;
 char pad1[8];
 float startValue;
 float endValue;
 float FUN_00069210(float t);
};
float Curve_69210::FUN_00069210(float t) {
 volatile float scale = startScale;
 volatile float delta = endScale - startScale;
 if (!(scale > 0.0f)) return 0.0f;
 if (delta >= 0.0f && t >= 0.0f && t <= 1.0f) scale = delta * t + startScale;
 if (!(scale > 0.0f)) return 0.0f;
 if (endValue - startValue >= 0.0f) return ((endValue - startValue) * t + startValue) / scale;
 return startValue / scale;
}