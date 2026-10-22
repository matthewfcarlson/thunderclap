#include "compat/ptr.h"
inline void* operator new(unsigned, void* p) {
    return p;
}
extern "C" void* memmove(void*, const void*, unsigned);
extern "C" void* memset(void*, int, unsigned);
void* Alloc(hulk_uintptr n);
class ChannelHandler_28e9b0 {
  public:
    ChannelHandler_28e9b0() { a = 0; }
    virtual void f0();
    int a;
};
class DefaultChannelHandler_28e9b0 : public ChannelHandler_28e9b0 {
  public:
    virtual void f0();
};
class NonCopyable_28e9b0 {
  public:
    NonCopyable_28e9b0() { a = 0; }
    virtual void f0();
    int a;
};
class ChannelLoader : public NonCopyable_28e9b0 {
  public:
    ChannelLoader();
    virtual void f0();
    int count;
    DefaultChannelHandler_28e9b0* tbl[16];
};
ChannelLoader::ChannelLoader() {
    count = 0;
    memset(tbl, 0, 64);
    DefaultChannelHandler_28e9b0* h = new (Alloc(8)) DefaultChannelHandler_28e9b0;
    if (h) {
        memmove(&tbl[1], &tbl[0], count << 2);
        tbl[0] = h;
        h->f0();
        count++;
    }
}
