class Gate_e30a0 {
  public:
    void H(int);
};
class TextSelector_e30a0 {
  public:
    virtual void End();
    void Run();
    char pad[0x150];
    int val;
    char pad2[0x1d94 - 0x158];
    Gate_e30a0* gate;
};
void TextSelector_e30a0::Run() {
    if (gate)
        gate->H(val);
    End();
}