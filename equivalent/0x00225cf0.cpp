// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00225cf0 @ 0x00225cf0
extern float __cdecl FUN_00225be0(int, int, int, unsigned char);
struct Object {
 char pad[0x224];
 unsigned char flag;
 char pad2[7];
 int value1;
 int value2;
 char pad3[4];
 float result1;
 float result2;
 void FUN_00225cf0(int input);
};
void Object::FUN_00225cf0(int input) {
 float result = FUN_00225be0(input, value1, value2, flag);
 result1 = result;
 result2 = result;
}