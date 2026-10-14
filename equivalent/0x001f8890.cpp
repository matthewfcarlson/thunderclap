// STATUS: equivalent (tools/equiv.py level 3: 81 inputs, branch coverage 20/20)
// FUN_001f8890 @ 0x001f8890
struct Entry_1f8890 { float value; char padding[36]; };
struct Object {
 char pad0[0x458];
 int enabled;
 char pad1[0x20];
 Entry_1f8890 entries[15];
 char pad2[12];
 int count;
 float target();
};
float Object::target() {
 float result = 0.0f;
 if (!enabled) return result;
 for (int i=0; i<count; ++i) {
  float v=entries[i].value;
  if (result < v) result=v;
 }
 return result;
}
