namespace hulkfight {
class XPAction {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual char vfunc_3(int, int);
    virtual void v4();
    virtual void v5();
    char pad[0x18];
    void* value;
    int enabled;
};
} // namespace hulkfight
struct Datum {
    char pad[16];
    float value;
};
class Result {
  public:
    void Apply(const char*, int);
};
class Manager {
  public:
    Result* Find();
};
extern Manager* gManager;
char hulkfight::XPAction::vfunc_3(int, int) {
    if (!enabled)
        return 0;
    int n = (int)((Datum*)value)->value;
    gManager->Find()->Apply("xp", n);
    return 1;
}