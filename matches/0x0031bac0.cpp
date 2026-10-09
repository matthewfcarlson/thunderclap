class pddiObject {
  public:
    pddiObject();
    virtual ~pddiObject();
    int a;
    int b;
};
pddiObject::pddiObject() : a(0), b(1) {}