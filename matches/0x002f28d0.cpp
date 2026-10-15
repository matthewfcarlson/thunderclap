typedef unsigned __int64 U64;
extern U64 __cdecl make(int);
class Manager {
  public:
    void send(U64, int, int, int, int);
};
extern Manager* gManager;
void __cdecl target(int a, int b, int c, int d, int e) {
    gManager->send(make(a), b, c, d, e);
}
