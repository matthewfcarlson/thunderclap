#include "gen/global.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
// data: scale_1fd830 = DAT_003f3ef4, zero_1fd830 = DAT_003f32e0

#include "compat/ptr.h"
class Result_1fd830 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual float Get();
};
struct CTriggerVolumeManager_nv_1fd830 {
    Result_1fd830* Find(unsigned long long key);
};
extern unsigned long long FUN_0027b020(unsigned int);

hulk_freg CTriggerVolumeManager::FUN_001fd830(unsigned int arg) {
    unsigned long long k = FUN_0027b020(arg);
    Result_1fd830* r = ((CTriggerVolumeManager_nv_1fd830*)this)->Find(k);
    if (!r)
        return DAT_003f32e0;
    return r->Get() * DAT_003f3ef4;
}
