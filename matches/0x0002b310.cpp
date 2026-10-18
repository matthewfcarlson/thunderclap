// FUN_0002b310 @ 0x0002b310
#include "decls/data/game/unknown.h"

struct Vec3_2b310 { unsigned int x, y, z; };
extern void __cdecl FUN_00224d70(float angle, Vec3_2b310* v);
class Obj_2b310 {
  public:
    void FUN_00028400(int a, Vec3_2b310 v);
    void FUN_0002b310(int a, float degrees);
};
void Obj_2b310::FUN_0002b310(int a, float degrees) {
    Vec3_2b310 v;
    v.x = (*(unsigned int*)&DAT_0048e084);
    v.y = (*(unsigned int*)&DAT_0048e088);
    v.z = (*(unsigned int*)&DAT_0048e08c);
    FUN_00224d70(degrees * 0.01745329238474369f, &v);
    FUN_00028400(a, v);
}
