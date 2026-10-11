extern "C" char DAT_0040c0bc[];
class FEDoScreen {
  public:
    int pad0[2];
    int a, b, c;
    char e;
    char pad[31];
    FEDoScreen(int, const char*);
};
extern void Format(char*, int, const char*, const char*);
FEDoScreen::FEDoScreen(int x, const char* s) {
    a = -1;
    b = -1;
    c = x;
    e = 0;
    *(int*)this = ((int)DAT_0040c0bc);
    Format((char*)this + 0x34, 0x20, "%s", s);
}