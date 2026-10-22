struct ParamValueName_161a00 {
    ParamValueName_161a00(int a);
    virtual void V0();
    char pad[12];
    int m10;
};

struct ParamName_161a00 : ParamValueName_161a00 {
    ParamName_161a00(int a, int b);
};

ParamName_161a00::ParamName_161a00(int a, int b) : ParamValueName_161a00(a) {
    m10 = b;
}
