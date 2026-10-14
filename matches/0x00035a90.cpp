class Inner_35a90 {
  public:
    bool Run();
};
class Thing_35a90 {
  public:
    char pad[0x11c];
    Inner_35a90* member;
    bool Run();
};
bool Thing_35a90::Run() {
    if (!member)
        return false;
    return member->Run();
}