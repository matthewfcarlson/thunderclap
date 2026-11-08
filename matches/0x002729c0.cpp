#include "compat/ptr.h"
#include "decls/data/records.h"

class Inner_2729c0 {
  public:
    virtual void First();
    virtual void Second();
};
// core::Drive (records.h CoreDrive): clears the state with a semaphore to release, under the IMutable lock at +0xc
class Target_2729c0 : public CoreDrive {
  public:
    void run(hulk_uintptr*);
};
void Target_2729c0::run(hulk_uintptr* x) {
    ((Inner_2729c0*)&vftableMutable)->First();
    signal = x;
    state = 0;
    ((Inner_2729c0*)&vftableMutable)->Second();
}
