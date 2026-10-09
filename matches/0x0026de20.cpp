class DebugConsole {
    char pad[0xa0];
    int field;

  public:
    void vfunc_10(int);
};
void DebugConsole::vfunc_10(int value) {
    field = value;
}