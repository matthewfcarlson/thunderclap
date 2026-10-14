// STATUS: equivalent (tools/equiv.py level 3: 48 inputs, branch coverage 12/12)
// FUN_00046030 @ 0x00046030
struct Key_46030 {
 unsigned int first, second;
 void FUN_0027af00();
 void FUN_0027b040(const char* text);
 void FUN_0027af70(const Key_46030* other);
};
extern Key_46030 DAT_004dc340;
extern unsigned int DAT_004dc348;
extern void __cdecl FUN_00363be0();
extern "C" int __cdecl _atexit(void (__cdecl *callback)());
struct Entry_46030 { Key_46030 key; float value; unsigned int reserved; };
struct Object {
 char padding[0x480];
 Entry_46030 entries[14];
 int count;
 void FUN_00046030(const char* text, float value);
};
void Object::FUN_00046030(const char* text, float value) {
 if (!(DAT_004dc348 & 1)) {
  DAT_004dc348 |= 1;
  DAT_004dc340.FUN_0027af00();
  _atexit(FUN_00363be0);
 }
 DAT_004dc340.FUN_0027b040(text);
 int oldCount = count;
 for (int i=0; i<count; ++i) {
  if (entries[i].key.first == DAT_004dc340.first && entries[i].key.second == DAT_004dc340.second) {
   entries[i].value = value;
   return;
  }
 }
 if (oldCount < 14) {
  entries[oldCount].key.FUN_0027af70(&DAT_004dc340);
  entries[count].value = value;
  ++count;
 }
}
