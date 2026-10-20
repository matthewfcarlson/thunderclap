#include "compat/ptr.h"
extern "C" char DAT_0042502c[];
struct MyFileStream {
    int v;
    int a;
    int b;
    int c;
};
class Stream {
  public:
    bool Try(MyFileStream* s, int x);
    void Close();
};
class Owner_1faf20 {
  public:
    char pad[4];
    Stream* stream;
    bool Open(int x);
};
bool Owner_1faf20::Open(int x) {
    MyFileStream local;
    local.v = 0;
    local.a = 0;
    local.b = 0;
    local.c = 0;
    local.v = ((hulk_intptr)DAT_0042502c);
    if (stream->Try(&local, x))
        return true;
    stream->Close();
    return false;
}