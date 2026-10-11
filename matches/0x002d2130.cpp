extern "C" char DAT_0042f0a8[];
class Entry {
  public:
    int Find(int, int);
};
class GeneratorBlendState {
  public:
    int vf;
    int a;
    int b;
    int c;
    int d;
    GeneratorBlendState(int x);
};
GeneratorBlendState::GeneratorBlendState(int x) {
    a = 0;
    vf = ((int)DAT_0042f0a8);
    b = 0;
    c = 0;
    d = 0;
    if (x != 0) {
        Entry* e = (Entry*)x;
        b = e->Find(0x50534f48, 0x31544c46);
        c = e->Find(0x50534556, 0x31544c46);
        d = e->Find(0x41564452, 0x31544c46);
    }
}