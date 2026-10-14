// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000a03c0 @ 0x000a03c0
extern float DAT_003f32e0;
float __cdecl FUN_000a0330(float);
float __cdecl FUN_000a02a0(float);
extern float DAT_003f32f4;
float Clamp3(float a, float b, float c) {
 float span = FUN_000a0330(c - b);
 if (FUN_000a0330(a - b) > span) {
  if (FUN_000a02a0(a - (span * DAT_003f32f4 + b)) > DAT_003f32e0)
   return FUN_000a02a0(c);
  return FUN_000a02a0(b);
 }
 return FUN_000a02a0(a);
}
