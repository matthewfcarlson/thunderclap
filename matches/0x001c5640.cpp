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