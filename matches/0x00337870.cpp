class Obj {
  public:
    int vft;
    int a;
    int b;
    Obj();
};

Obj::Obj() {
    vft = 0x434578;
    a = 0;
    b = 0;
}