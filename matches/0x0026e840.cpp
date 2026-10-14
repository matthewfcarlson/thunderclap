extern char* strncpy(char*, const char*, int);

class Console2 {
  public:
    void Func(void* msg, int n);
};

struct Msg_26e840 {
    int tag;
    void* self;
    unsigned p3;
    unsigned p4;
    char buf[84];
};

class DebugConsole {
  public:
    char pad[0xa4];
    Console2* mConsole;
    void vfunc_8(const char* s, unsigned p3, unsigned p4);
};

void DebugConsole::vfunc_8(const char* s, unsigned p3, unsigned p4) {
    Console2* c = mConsole;
    Msg_26e840 msg;
    msg.tag = 6;
    msg.self = this;
    msg.p3 = p3;
    msg.p4 = p4;
    strncpy(msg.buf, s, 0x54);
    msg.buf[83] = 0;
    c->Func(&msg, 100);
}
