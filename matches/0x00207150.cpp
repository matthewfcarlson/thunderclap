class C {
  public:
    char pad[0x570];
    int a[2];
    bool Check(int);
    int Get(int);
    void Do(int);
    void Finish(int);
    bool Run();
};

bool C::Run() {
    for (;;) {
        int n = 0;
        if (a[0] > 0)
            n = 1;
        if (a[1] > 0)
            n++;
        if (n >= 2) {
            int i;
            for (i = 0; i < 2; i++) {
                if (a[i] > 0 && !Check(a[i])) {
                    Finish(a[i]);
                    return true;
                }
            }
            int r = Get(0);
            if (r > 0)
                Do(r);
        } else {
            break;
        }
    }
    return false;
}
