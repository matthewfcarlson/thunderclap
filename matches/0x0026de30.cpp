class DebugConsole {
  public:
    char pad[0x9c];
    int field;
    void vfunc_11(int);
};
void DebugConsole::vfunc_11(int value) {
    field = value;
}