extern "C" char VT_6db80[];
class Base_6db80 {
  public:
    virtual ~Base_6db80() {}
    virtual void Cast();
    Base_6db80();
};
Base_6db80::Base_6db80() {
    *(int*)this = (int)VT_6db80;
}
