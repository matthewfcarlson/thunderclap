// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0002b310 @ 0x0002b310
struct Vec3 { unsigned int x, y, z; };
extern unsigned int DAT_0048e084, DAT_0048e088, DAT_0048e08c;
extern void __cdecl FUN_00224d70(float angle, Vec3* v);
class Obj {
  public:
    void FUN_00028400(int a, Vec3 v);
    void FUN_0002b310(int a, float degrees);
};
void Obj::FUN_0002b310(int a, float degrees) {
    Vec3 v;
    v.x = DAT_0048e084;
    v.y = DAT_0048e088;
    v.z = DAT_0048e08c;
    FUN_00224d70(degrees * 0.01745329238474369f, &v);
    FUN_00028400(a, v);
}
