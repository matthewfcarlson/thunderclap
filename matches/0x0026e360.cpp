extern "C" char DAT_003f6098[];
extern "C" char DAT_0042af64[];
extern "C" char DAT_0042b474[];
extern "C" char DAT_0042b47c[];
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
    a = ((int)DAT_0042b47c);
    b = ((int)DAT_0042b474);
    Init();
    gSaved = c;
    b = ((int)DAT_0042af64);
    a = ((int)DAT_003f6098);
    gState = 0;
}