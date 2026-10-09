typedef unsigned int u32;
extern void Init();
extern u32 gSaved;
extern u32 gState;
class ConsoleClient {
  public:
    u32 a, b, c;
    void Run();
};
void ConsoleClient::Run() {
    a = 0x42b47c;
    b = 0x42b474;
    Init();
    gSaved = c;
    b = 0x42af64;
    a = 0x3f6098;
    gState = 0;
}