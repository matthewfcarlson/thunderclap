class IValueChangedSender;
class Listener {
  public:
    virtual void f();
    virtual void Changed(IValueChangedSender*);
};
class IValueChangedSender {
  public:
    virtual void vfunc_0();
    Listener* listeners[4];
};
void IValueChangedSender::vfunc_0() {
    for (int i = 0; i < 4; ++i) {
        if (listeners[i])
            listeners[i]->Changed(this);
    }
}