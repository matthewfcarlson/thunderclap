#include "decls/data/records.h"
struct I0 {
    virtual void f();
    virtual void g();
};
struct I3 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d(unsigned int);
};
// core::FileCompletionRequest::vfunc_7 (records.h CoreCompletionRequest): one request less pending on the file
// (CoreFile field18, under its IMutable lock), then the callback's slot 3 with the context
struct FileCompletionRequest_273700 : CoreCompletionRequest {
    void vfunc_7();
};
void FileCompletionRequest_273700::vfunc_7() {
    ((I0*)&((CoreFile*)file)->vftableMutable)->f();
    --((CoreFile*)file)->field18;
    ((I0*)&((CoreFile*)file)->vftableMutable)->g();
    ((I3*)callback)->d(context);
}
