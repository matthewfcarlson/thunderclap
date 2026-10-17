// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001b3250 @ 0x001b3250
struct Entry { float low; float middle; float high; char pad[0xa8]; };
extern Entry DAT_004e18b0[];
struct Object { char pad[12]; int index; int FUN_001b3250(float value); };
int Object::FUN_001b3250(float value) {
 int i = index;
 if (i < 0 || value < DAT_004e18b0[i].low) return 0;
 if (value < DAT_004e18b0[i].middle) return 1;
 return value < DAT_004e18b0[i].high ? 2 : 3;
}