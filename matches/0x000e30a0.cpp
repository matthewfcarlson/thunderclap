class Gate {
  public:
    void H(int);
};
class Obj {
  public:
    virtual void End();
    void Run();
    char pad[0x150];
    int val;
    char pad2[0x1d94 - 0x158];
    Gate* gate;
};
void Obj::Run() {
    if (gate)
        gate->H(val);
    End();
}