class Result_44410 {
  public:
    char pad[8];
    int value;
};
class Inner_44410 {
  public:
    virtual Result_44410* f0();
    virtual Result_44410* f1();
    virtual Result_44410* f2();
    virtual Result_44410* f3();
    virtual Result_44410* f4();
    virtual Result_44410* f5();
    virtual Result_44410* f6();
    virtual Result_44410* f7();
    virtual Result_44410* f8();
    virtual Result_44410* f9();
    virtual Result_44410* f10();
    virtual Result_44410* f11();
};
class Source_44410 {
  public:
    char pad[8];
    Inner_44410* item;
    int FUN_00044410();
};
int Source_44410::FUN_00044410() {
    if (!item)
        return 0;
    return item->f11()->value;
}