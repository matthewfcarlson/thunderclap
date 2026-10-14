class Callback_f8dd0 {
  public:
    virtual void call(int);
};
class NamedValueInt {
  public:
    virtual void f0();
    virtual void f1();
    char pad[0x3c];
    int value40;
    int value44;
    Callback_f8dd0* notifier48;
};
void NamedValueInt::f1() {
    value40 = value44;
    if (notifier48)
        notifier48->call(value44);
    f0();
}