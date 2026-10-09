struct PartA {
    void Init();
};
struct PartB {
    void Init();
};
struct End {
    void Finish();
};
class GrappleExecuteTrack {
  public:
    virtual void v0();
    char pad4[0x10];
    PartB p14;
    char pad18[0x0c];
    PartA p24;
    void Run();
};
void GrappleExecuteTrack::Run() {
    *(unsigned long*)this = 0x413738;
    ((PartA*)((char*)this + 0x24))->Init();
    ((PartB*)((char*)this + 0x14))->Init();
    ((End*)this)->Finish();
}
