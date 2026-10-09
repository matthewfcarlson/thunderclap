class Result {
  public:
    char pad[8];
    int value;
};
class Inner {
  public:
    virtual Result* f0();
    virtual Result* f1();
    virtual Result* f2();
    virtual Result* f3();
    virtual Result* f4();
    virtual Result* f5();
    virtual Result* f6();
    virtual Result* f7();
    virtual Result* f8();
    virtual Result* f9();
    virtual Result* f10();
    virtual Result* f11();
};
class Source {
  public:
    char pad[8];
    Inner* item;
    int FUN_00044410();
};
int Source::FUN_00044410() {
    if (!item)
        return 0;
    return item->f11()->value;
}