#include "gen/owners.h"
class Thing_25d780 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void Act(owners::Owner_25d780*);
    virtual void d();
    virtual int Check(owners::Owner_25d780*);
};
void owners::Owner_25d780::FUN_0025d780() {
    if (mData) {
        Thing_25d780* t = (Thing_25d780*)(mData - 4);
        if (t && t->Check(this) == 3)
            t->Act(this);
    }
    mState = 4;
}