// STATUS: equivalent (tools/equiv.py level 3: 20007 inputs, branch coverage 2/2)
// FUN_001fcea0 @ 0x001fcea0
class Input_1fcea0 {
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
struct Record_1fcea0 {
    char data[0x40];
    void first(int);
    void second(float);
    void third(int);
};
class Owner_1fcea0 {
  public:
    char pad[0x20c];
    int count;
    Record_1fcea0* records;
    bool add(Input_1fcea0*);
};
bool Owner_1fcea0::add(Input_1fcea0* p) {
    if (count < 0x100) {
        char tmp[12];
        int a = p->get(tmp);
        records[count].first(a);
        float arg1 = p->value();
        records[count].second(arg1);
        int b = p->process();
        records[count].third(b);
        ++count;
        return true;
    }
    return false;
}