#include "compat/ptr.h"
class Obj_69d30 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float GetBase();
    char pad4[0x10 - 4];
    float unused10;
    float scale;
    hulk_freg Get();
};

hulk_freg Obj_69d30::Get()
{
    hulk_freg base = GetBase();
    if (base <= 0.0f)
        return -1.0f;
    if (scale <= 0.0f)
        return -1.0f;
    return base * scale;
}
