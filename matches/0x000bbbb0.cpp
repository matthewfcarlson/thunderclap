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
extern char gFlag;
extern char msg[];
class Obj {
  public:
    void* v;
    void* p;
    int Cancel(int, int);
};
int Obj::Cancel(int a, int b) {
    if (!p)
        return -1;
    Event e(msg);
    gRoot->recv->Fire(&e);
    gFlag = 1;
    return 0;
}