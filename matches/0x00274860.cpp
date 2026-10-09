class Drive {
  public:
    virtual void A();
    virtual void B();
    char pad[0x10];
    int count;
};
class DriveSub {
  public:
    virtual void A();
    virtual void B();
};
class Obj {
  public:
    int vf;
    char pad[4];
    Drive* drive;
    void Run();
};
void Obj::Run() {
    vf = 0x42b9bc;
    ((DriveSub*)((char*)drive + 4))->A();
    --drive->count;
    ((DriveSub*)((char*)drive + 4))->B();
    drive->B();
    vf = 0x42b914;
}