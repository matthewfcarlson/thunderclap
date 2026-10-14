class Ref_1cbf90 {
  public:
    virtual void f0();
    virtual void Release();
};
class Worker_1cbf90 {
  public:
    void run();
    char pad[0x28];
};
class Root_1cbf90 {
  public:
    char pad0[12];
    int a;
    int b;
    int c;
    char pad14[8];
    Ref_1cbf90* r20;
    Worker_1cbf90 first;
    char padEnd[0x3b4];
    Ref_1cbf90* r400;
    void clear();
};
void Root_1cbf90::clear() {
    if (r400) {
        r400->Release();
        r400 = 0;
    }
    if (r20) {
        r20->Release();
        r20 = 0;
    }
    b = a;
    Worker_1cbf90* p = &first;
    for (int i = 0; i < 24; i++, p++)
        p->run();
}
