class Inner_86240 {
  public:
    void Step();
};
class Target_86240 {
  public:
    char pad[0x1c];
    Inner_86240* member;
    void Run();
};
extern bool FUN_0008db80();
extern void FUN_0008db90();
void Target_86240::Run() {
    if (member != 0) {
        while (FUN_0008db80()) {
            FUN_0008db90();
            member->Step();
        }
    }
}