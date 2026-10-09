class Inner {
  public:
    void Step();
};
class Target {
  public:
    char pad[0x1c];
    Inner* member;
    void Run();
};
extern bool FUN_0008db80();
extern void FUN_0008db90();
void Target::Run() {
    if (member != 0) {
        while (FUN_0008db80()) {
            FUN_0008db90();
            member->Step();
        }
    }
}