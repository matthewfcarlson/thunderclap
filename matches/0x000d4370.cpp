class Obj_d4370 {
  public:
    char pad[0x10];
    int a;
    char rest[0x7f8];
    unsigned char b;
    void Target(int);
};
class Other_d4370 {
  public:
    void Help(Obj_d4370*);
};
void Obj_d4370::Target(int x) {
    ((Other_d4370*)x)->Help(this);
    a = 0;
    b = 1;
}