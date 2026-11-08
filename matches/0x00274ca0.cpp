#include "compat/ptr.h"
#include "decls/data/records.h"
extern "C" char DAT_0042b914[];
extern "C" char DAT_0042b954[];
extern "C" char DAT_0042b9dc[];
extern "C" int* FUN_002705f0();
class Intf {
  public:
    virtual void f0();
    virtual void f1();
};
class Ref_274ca0 {
  public:
    virtual void v0();
};
// core::FileCompletionRequest's constructor (records.h CoreCompletionRequest): core::Request, then
// core::CompletionCallbackRequest (the queuing thread), then its own (the file, a callback, its context); a
// reference to the callback and to the file, and one more pending request on the file (CoreFile field18)
class FileCompletionRequest_274ca0 : public CoreCompletionRequest {
  public:
    FileCompletionRequest_274ca0* Init(void* x, void* y, void* z, unsigned int w);
};
FileCompletionRequest_274ca0* FileCompletionRequest_274ca0::Init(void* x, void* y, void* z, unsigned int w) {
    vftable = DAT_0042b914;
    next = 0;
    FUN_002705f0();
    vftable = DAT_0042b9dc;
    thread = x;
    FUN_002705f0();
    vftable = DAT_0042b954;
    file = y;
    callback = z;
    context = w;
    FUN_002705f0();
    ((Ref_274ca0*)callback)->v0();
    ((Intf*)&((CoreFile*)file)->vftableMutable)->f0();
    ((CoreFile*)file)->field18++;
    ((Intf*)&((CoreFile*)file)->vftableMutable)->f1();
    ((Ref_274ca0*)file)->v0();
    return this;
}
