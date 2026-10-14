extern float Zero_1cd650;
void Stop();
class Thing_1cd650 {
  public:
    char pad[0x11a8];
    float timer;
    int a;
    int b;
    void Update(float dt);
};
void Thing_1cd650::Update(float dt) {
    if (timer != Zero_1cd650) {
        timer = timer - dt;
        if (timer <= Zero_1cd650) {
            timer = 0.0f;
            Stop();
            b = 0;
            a = 0;
        }
    }
}