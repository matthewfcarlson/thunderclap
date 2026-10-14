struct Sub2_2eccd0 {
    void Do();
};

struct PA {
    char pad0[0x38];
    float f38;
    char pad1[0x2c];
    Sub2_2eccd0 s;
};

struct PB {
    char pad0[0x80];
    float f80;
    char pad1[0x2c];
    Sub2_2eccd0 s;
};

extern char gEnabled_2eccd0;
extern PA* gPA;
extern PB* gPB;
extern const float kScale_2eccd0;

class Cls_2eccd0 {
  public:
    char pad[0x2c];
    float a;
    float b;
    void Set(float f);
};

void Cls_2eccd0::Set(float f) {
    a = f;
    if (!gEnabled_2eccd0)
        return;
    b = kScale_2eccd0 * f;
    if (gPA) {
        gPA->s.Do();
        gPA->f38 = b;
    } else if (gPB) {
        gPB->s.Do();
        gPB->f80 = b;
    }
}
