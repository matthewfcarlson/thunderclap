class Ref {
  public:
    virtual void f0();
    virtual void Release();
};
class Worker {
  public:
    void run();
    char pad[0x28];
};
class Root {
  public:
    char pad0[12];
    int a;
    int b;
    int c;
    char pad14[8];
    Ref* r20;
    Worker first;
    char padEnd[0x3b4];
    Ref* r400;
    void clear();
};
void Root::clear() {
    if (r400) {
        r400->Release();
        r400 = 0;
    }
    if (r20) {
        r20->Release();
        r20 = 0;
    }
    b = a;
    Worker* p = &first;
    for (int i = 0; i < 24; i++, p++)
        p->run();
}
