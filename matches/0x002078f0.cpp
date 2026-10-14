class Sub_2078f0 {
  public:
    int Check();
    int Other();
};
class Obj_2078f0 {
  public:
    char pad[0xaec];
    Sub_2078f0* m;
    char flag;
    char Run(char);
    void Do(Sub_2078f0*);
    char Finish();
};
extern char gFlag_2078f0;
char Obj_2078f0::Run(char b) {
    if (!m)
        return 0;
    int x = m->Check();
    flag = 1;
    if (x != 3) {
        if (b)
            Do(m);
        else {
            if (gFlag_2078f0) {
                m->Other();
                return 0;
            }
            Do(m);
            return 0;
        }
    }
    return Finish();
}
