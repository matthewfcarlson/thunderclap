#include "gen/pure3d.h"

class Item_299080 {
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
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void reset();
};
struct Entry_299080 {
    char pad[8];
    Item_299080* item;
};
struct Array {
    Entry_299080* first;
    Entry_299080* last;
    unsigned char size() const { return (unsigned char)(last - first); }
};
struct Vec_299080 {
    char pad[0x3c];
    Array arr;
};
class Ref_299080 {
  public:
    virtual void f0();
    virtual void release();
};

void pure3d::CompositeDrawable::vfunc_14() {
    if ((*(Ref_299080 * *)&this->f_10)) {
        (*(Ref_299080 * *)&this->f_10)->release();
        (*(Ref_299080 * *)&this->f_10) = 0;
    }
    unsigned char n = (*(Vec_299080 * *)&this->f_44)->arr.size();
    for (unsigned char i = 0; i < n; ++i)
        (*(Vec_299080 * *)&this->f_44)->arr.first[i].item->reset();
}
