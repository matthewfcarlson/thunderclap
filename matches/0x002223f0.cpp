extern "C" char DAT_00427260[];
class Base {
  public:
    virtual void Init();
};
void InitPartition();
class PartitionDriver {
  public:
    virtual void V0();
    char pad[12];
    Base* mSource;
    int a, b, c;
    PartitionDriver* Run(Base* source);
};
PartitionDriver* PartitionDriver::Run(Base* source) {
    InitPartition();
    *(int*)this = ((int)DAT_00427260);
    mSource = source;
    mSource->Init();
    a = 0;
    b = 0;
    c = *(int*)((char*)mSource + 0x10) - 1;
    return this;
}