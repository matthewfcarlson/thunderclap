#include "decls/data/game/global.h"
// data: zero = DAT_003f32e0

#include "compat/ptr.h"
struct Value {
    char pad[0x14];
    float v;
};
struct Link {
    char pad[0x1c];
    Value* val;
};
extern "C" float __cdecl blend(Value*, Value*);
class Obj {
  public:
    char a[0x14];
    Link* left;
    Link* right;
    char b[0x70];
    void* first;
    void* second;
    char c[0x5f];
    char flag;
    hulk_freg Get();
};
hulk_freg Obj::Get() {
    if (flag)
        return DAT_003f32e0;
    if (first && second) {
        Value* r = right->val;
        Value* l = left->val;
        return blend(l, r);
    }
    if (first)
        return left->val->v;
    return right->val->v;
}