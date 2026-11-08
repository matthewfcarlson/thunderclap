#include "compat/ptr.h"
#include "decls/data/records.h"
extern "C" char DAT_0042b914[];
extern "C" char DAT_0042b99c[];
struct Inner_274e60 {
    virtual void a();
    virtual void b();
};
struct File {
    virtual void a();
};
extern "C" int* FUN_002705f0();
// core::FileRequest's constructor (records.h CoreRequest): a reference to the file (slot 0) and one more pending
// request on it (CoreFile field18, under its IMutable lock)
struct FileRequest_274e60 : CoreRequest {
    CoreRequest* run(hulk_uintptr arg);
};
CoreRequest* FileRequest_274e60::run(hulk_uintptr arg) {
    vftable = DAT_0042b914;
    next = 0;
    FUN_002705f0();
    vftable = DAT_0042b99c;
    file = (void*)arg;
    FUN_002705f0();
    ((Inner_274e60*)&((CoreFile*)file)->vftableMutable)->a();
    ++((CoreFile*)file)->field18;
    ((Inner_274e60*)&((CoreFile*)file)->vftableMutable)->b();
    ((File*)file)->a();
    return this;
}
