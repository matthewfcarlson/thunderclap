#include "compat/ptr.h"
extern "C" char DAT_00427260[];
class Base_2223f0 {
  public:
    virtual void Init();
};
void __fastcall InitPartition(void*);
class PartitionDriver {
  public:
    virtual void V0();
    char pad[12];
    Base_2223f0* mSource;
    int a, b, c;
    PartitionDriver* Run(Base_2223f0* source);
};
PartitionDriver* PartitionDriver::Run(Base_2223f0* source) {
    InitPartition((void*)(this));
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00427260);
    mSource = source;
    mSource->Init();
    a = 0;
    b = 0;
    c = *(int*)((char*)mSource + 0x10) - 1;
    return this;
}