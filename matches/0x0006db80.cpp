extern "C" char VT[];
class Base {
  public:
    virtual ~Base() {}
    virtual void Cast();
    Base();
};
Base::Base() {
    *(int*)this = (int)VT;
}
