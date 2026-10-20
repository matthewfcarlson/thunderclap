#include "compat/ptr.h"
extern "C" char DAT_0042b914[];
extern "C" char DAT_0042b99c[];
// Same code shape as 0x002737f0 (propagated; names are from that function)
struct Sub_273b50 {
    virtual void f();
    virtual void g();
};
struct V {
    virtual void f();
    virtual void g();
};
struct Inner_273b50 {
    void* v;
    Sub_273b50 sub;
    char pad[16];
    int ref;
};
struct FileRequest_273b50 {
    void* v;
    char pad[4];
    Inner_273b50* p;
    void run();
};
void FileRequest_273b50::run() {
    v = (void*)((hulk_intptr)DAT_0042b99c);
    p->sub.f();
    --p->ref;
    p->sub.g();
    ((V*)p)->g();
    v = (void*)((hulk_intptr)DAT_0042b914);
}
