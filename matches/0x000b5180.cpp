#include "decls/data/game/global.h"
// data: flag = DAT_004e222c

struct Event {
    char data[32];
    Event(const char*);
};
struct Receiver {
    void Send(Event*);
};
struct Global {
    char pad[0x30];
    Receiver* rec;
};
extern Global* g;
void target() {
    Event e("JumpMarkerSelectionCancelled");
    g->rec->Send(&e);
    (*(unsigned char*)&DAT_004e222c) = 1;
}