class Base {
  public:
    Base();
    virtual void F();
};
class BMPHandler : public Base {
  public:
    BMPHandler();
    virtual void F();
};
BMPHandler::BMPHandler() {}