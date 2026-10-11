extern "C" char DAT_00410bd4[];
class Sub {
  public:
    void Init();
};
class FinishCall {
  public:
    void Finish();
};
class ThreatCondition {
  public:
    void Run();
};
void ThreatCondition::Run() {
    *(void**)this = (void*)((int)DAT_00410bd4);
    ((Sub*)((char*)this + 0x10))->Init();
    ((FinishCall*)this)->Finish();
}
