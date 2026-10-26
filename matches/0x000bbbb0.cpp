#include "decls/data/game/global.h"
// data: gFlag = DAT_004e222c, msg = DAT_00407974

class Event {
  public:
    Event(const char*);
    char data[32];
};
class Receiver {
  public:
    void Fire(Event*);
};
class Root {
    char pad[48];

  public:
    Receiver* recv;
};
extern Root* gRoot;
class Obj {
  public:
    void* v;
    void* p;
    int Cancel(int, int);
};
int Obj::Cancel(int a, int b) {
    if (!p)
        return -1;
    Event e(((char*)&DAT_00407974));
    gRoot->recv->Fire(&e);
    DAT_004e222c = 1;
    return 0;
}