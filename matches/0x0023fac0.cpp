#include "decls/data/engine/audio.h"
// data: gData = DAT_004cc02c

struct Buf {
    short count;
};
class X {
  public:
    X();
    char* ptr;
    short mode;
    short pad;
    short value;
};
X::X() {
    ptr = (*(char**)&DAT_004cc02c);
    ++((short*)(*(char**)&DAT_004cc02c))[-2];
    value = 0;
    mode = 2;
}