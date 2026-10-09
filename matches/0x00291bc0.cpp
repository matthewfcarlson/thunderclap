class Base {
  public:
    Base();
    virtual void F();
};
class PNGHandler : public Base {
  public:
    PNGHandler();
};
PNGHandler::PNGHandler() {}