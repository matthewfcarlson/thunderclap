// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 22/22)
// FUN_001687a0 @ 0x001687a0
struct Object {
 char padding[0x1b0c];
 float value;
 float third;
 float FUN_000360b0();
 float FUN_00036090();
};
extern bool __cdecl FUN_00018960(float, float, float);
// equiv-conv: target ecx esi stack stack
bool __cdecl target(Object* object, unsigned comparison, int source, float scale) {
 if (!object) return false;
 float value = object->value;
 float base;
 switch(source) {
 case 1: base = object->FUN_00036090(); break;
 case 2: base = object->FUN_000360b0(); break;
 case 3: base = object->third; break;
 default: base = 1.0f; break;
 }
 float threshold = base * scale;
 switch(comparison) {
 case 0: return value < threshold;
 case 1: return value <= threshold;
 case 2: return FUN_00018960(value, threshold, 0.00001f);
 case 3: return !FUN_00018960(value, threshold, 0.00001f);
 case 4: return value >= threshold;
 case 5: return value > threshold;
 default: return false;
 }
}