struct Sub2 {
    void Do();
};

struct PA {
    char pad0[0x38];
    float f38;
    char pad1[0x2c];
    Sub2 s;
};

struct PB {
    char pad0[0x80];
    float f80;
    char pad1[0x2c];
    Sub2 s;
};

extern char gEnabled;
extern PA* gPA;
extern PB* gPB;
extern const float kScale;

class Cls {
  public:
    char pad[0x2c];
    float a;
    float b;
    void Set(float f);
};

void Cls::Set(float f) {
    a = f;
    if (!gEnabled)
        return;
    b = kScale * f;
    if (gPA) {
        gPA->s.Do();
        gPA->f38 = b;
    } else if (gPB) {
        gPB->s.Do();
        gPB->f80 = b;
    }
}
