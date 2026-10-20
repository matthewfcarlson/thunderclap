#include "compat/ptr.h"
extern "C" char DAT_003f6098[];
extern "C" char DAT_00428760[];
class DataReader_23bb30 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
};
class StreamDataReader : public DataReader_23bb30 {
  public:
    virtual void D();
    virtual void E();
    virtual void F();
    int pad;
    DataReader_23bb30* mObj;
    virtual StreamDataReader* vfunc_2(int);
};
extern void Destroy(StreamDataReader*);
StreamDataReader* StreamDataReader::vfunc_2(int flags) {
    DataReader_23bb30* p = mObj;
    ((hulk_intptr*)this)[0] = ((hulk_intptr)DAT_00428760);
    p->B();
    ((hulk_intptr*)this)[0] = ((hulk_intptr)DAT_003f6098);
    if (flags & 1)
        Destroy(this);
    return this;
}