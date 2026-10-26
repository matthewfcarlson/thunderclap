// cl-flags: /O2 /GR /GX
#include "decls/data/engine/core.h"
// data: g_Global_4CDBB0 = DAT_004cdbb0

class IRefCount {
  public:
    virtual void AddRef() = 0;
    virtual void Release() = 0;
    virtual ~IRefCount() throw() {}
};

class BaseObject {
  public:
    virtual ~BaseObject() throw() {}
};

class ControllerBuffer : public IRefCount, public BaseObject {
  public:
    int mUnk8;
    char pad_C[4];
    int mUnk10;
    char pad_24[0x10];
    int mUnk24;
    int mUnk28;

    ~ControllerBuffer() throw();
};

extern "C" void __cdecl FUN_00266f00(int, int);

ControllerBuffer::~ControllerBuffer() throw() {
    int a = mUnk10;
    int b = mUnk28;
    FUN_00266f00(b, a);

    int c = mUnk24;
    int d = mUnk28;
    FUN_00266f00(d, c);

    DAT_004cdbb0 = mUnk8;
}