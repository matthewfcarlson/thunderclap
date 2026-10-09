extern int gFlags;
extern int gCache[4096];
class C {
public:
 char pad[0x64];
 int a[8];
 int b[8];
 void f(int index, int value1, int value2);
};
void C::f(int index, int value1, int value2) {
 if (a[index] != value1) {
  a[index] = value1;
  gFlags |= 0x800;
  gCache[index * 32] = value1;
 }
 if (b[index] != value2) {
  b[index] = value2;
  gFlags |= 0x800;
  gCache[index * 32 + 2] = value2;
 }
}