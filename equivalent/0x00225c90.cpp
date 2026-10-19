// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00225c90 @ 0x00225c90
struct EntityData { char pad[0x14]; float scale; };
struct Object {
 char pad0[0x20]; EntityData* data;
 char pad1[0x200]; unsigned char flag;
 char pad2[3]; float factor;
 int valueA;
 int valueB;
 char pad3[8]; float offset;
 float FUN_00225c90(float amount);
};
float __cdecl FUN_00225be0(float, int, int, unsigned char, unsigned char, int, int);
float Object::FUN_00225c90(float amount) {
 return FUN_00225be0(data->scale * factor * amount + offset, valueA, valueB, flag, flag, valueB, valueA);
}