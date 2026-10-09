class Obj {
  public:
    char pad[0x10];
    int a;
    char rest[0x7f8];
    unsigned char b;
    void Target(int);
};
class Other {
  public:
    void Help(Obj*);
};
void Obj::Target(int x) {
    ((Other*)x)->Help(this);
    a = 0;
    b = 1;
}