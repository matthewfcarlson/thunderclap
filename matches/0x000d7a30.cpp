class IValueChangedSender { public: virtual void f0(); };
class IValueChangedReceiver { public: virtual void f1(); };
class FEObject : public IValueChangedSender, public IValueChangedReceiver {
public:
 virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8();
 virtual float vfunc_9();
 char pad[0xA0 - 8];
 float value;
};
float FEObject::vfunc_9() { return value; }