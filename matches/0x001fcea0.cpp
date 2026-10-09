class Input {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual int get(void*);
    virtual float value();
    int process();
};
struct Record {
    char data[0x40];
    void first(int);
    void second(float);
    void third(int);
};
class Owner {
  public:
    char pad[0x20c];
    int count;
    Record* records;
    bool add(Input*);
};
bool Owner::add(Input* p) {
    if (count < 0x100) {
        char tmp[12];
        int a = p->get(tmp);
        records[count].first(a);
        records[count].second(p->value());
        int b = p->process();
        records[count].third(b);
        ++count;
        return true;
    }
    return false;
}