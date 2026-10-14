struct Snd_1c16e0 {
    virtual void v0();
    virtual void Play(int, float, float, unsigned char);
};
extern Snd_1c16e0* gSnd;
class Obj_1c16e0 {
  public:
    char p[0xd0];
    float a;
    float b;
    unsigned char c;
    void Set(float x, float y);
};
void Obj_1c16e0::Set(float x, float y) {
    a = x;
    b = y;
    if (x != 0.0f && gSnd) {
        gSnd->Play(1, x, y, c);
        return;
    }
    gSnd->Play(0, x, y, c);
}
