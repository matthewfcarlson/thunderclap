class AgentOwner {
  public:
    virtual void Init();
};
class BaseAgent {
  public:
    virtual void Dummy();
    BaseAgent();
    int a;
    int b;
    char c;
    char pad[3];
    int d;
    int fields[16];
    int neg;
};
class CCharacterAgent : public BaseAgent {
  public:
    virtual void Dummy();
    CCharacterAgent(AgentOwner* p);
    AgentOwner* owner;
};
BaseAgent::BaseAgent() {
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    neg = -1;
    for (int i = 0; i < 16; i++)
        fields[i] = 0;
}
CCharacterAgent::CCharacterAgent(AgentOwner* p) {
    owner = p;
    p->Init();
}