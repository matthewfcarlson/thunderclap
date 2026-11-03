// Same code shape as 0x001c5640 (propagated; names are from that function)
#include "gen/Render.h"
class Store {
  public:
    virtual void f();
    void Cleanup2();
    ~Store();
    int mData;
};
Store::~Store() {
    ((Render::StoreBase *)this)->FUN_001c7720();
    Cleanup2();
}