#include "compat/ptr.h"
extern "C" char DAT_003f6098[];
extern "C" char DAT_0042c95c[];
class IRefCount {
  public:
    virtual void f0();
    virtual void Release() throw();
};
class ChannelLoader {
  public:
    int vf;
    int pad;
    int count;
    IRefCount* items[1];
    void cleanup() throw();
};
void ChannelLoader::cleanup() throw() {
    vf = ((hulk_intptr)DAT_0042c95c);
    for (int i = 0; i < count; ++i) {
        if (items[i]) {
            items[i]->Release();
            items[i] = 0;
        }
    }
    vf = ((hulk_intptr)DAT_003f6098);
}
