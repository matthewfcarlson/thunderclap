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
extern unsigned char flag;
void target() {
    Event e("JumpMarkerSelectionCancelled");
    g->rec->Send(&e);
    flag = 1;
}