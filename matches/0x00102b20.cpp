class Ref {
  public:
    virtual void a();
    virtual void Release();
};
class CMoveAgent {
  public:
    virtual ~CMoveAgent();
    void finish();
    char pad[0x64];
    Ref* member;
};
CMoveAgent::~CMoveAgent() {
    member->Release();
    member = 0;
    finish();
}
