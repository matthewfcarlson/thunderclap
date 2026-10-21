#include "compat/ptr.h"
struct BinkInfo {
    char pad[0x14];
    unsigned width;
    unsigned height;
};
namespace movie {
class PlayerBink {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual hulk_freg vfunc_14();
    virtual void v15();
    char pad[0x18];
    BinkInfo* info;
};
hulk_freg PlayerBink::vfunc_14() {
    if (info)
        return (float)info->width / (float)info->height;
    return 0.0f;
}
} // namespace movie