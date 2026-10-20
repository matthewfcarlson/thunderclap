#include "compat/ptr.h"
extern "C" char DAT_0042b914[];
extern "C" char DAT_0042b99c[];
struct Sub_2737f0 {
    virtual void f();
    virtual void g();
};
struct V {
    virtual void f();
    virtual void g();
};
struct Inner_2737f0 {
    void* v;
    Sub_2737f0 sub;
    char pad[16];
    int ref;
};
struct FileRequest_2737f0 {
    void* v;
    char pad[4];
    Inner_2737f0* p;
    void run();
};
void FileRequest_2737f0::run() {
    v = (void*)((hulk_intptr)DAT_0042b99c);
    p->sub.f();
    --p->ref;
    p->sub.g();
    ((V*)p)->g();
    v = (void*)((hulk_intptr)DAT_0042b914);
}
