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
class Owner_1fd830 {
  public:
    hulk_freg Probe(unsigned int arg);
    Result_1fd830* Find(unsigned long long key);
};
extern unsigned long long FUN_0027b020(unsigned int);
extern const float zero_1fd830;
extern const float scale_1fd830;
hulk_freg Owner_1fd830::Probe(unsigned int arg) {
    unsigned long long k = FUN_0027b020(arg);
    Result_1fd830* r = Find(k);
    if (!r)
        return zero_1fd830;
    return r->Get() * scale_1fd830;
}
