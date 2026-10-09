class Sub {
  public:
    int Check();
    int Other();
};
class Obj {
  public:
    char pad[0xaec];
    Sub* m;
    char flag;
    char Run(char);
    void Do(Sub*);
    char Finish();
};
extern char gFlag;
char Obj::Run(char b) {
    if (!m)
        return 0;
    int x = m->Check();
    flag = 1;
    if (x != 3) {
        if (b)
            Do(m);
        else {
            if (gFlag) {
                m->Other();
                return 0;
            }
            Do(m);
            return 0;
        }
    }
    return Finish();
}
