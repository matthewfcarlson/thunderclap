extern float Zero;
void Stop();
class Thing {
public:
    char pad[0x11a8];
    float timer;
    int a;
    int b;
    void Update(float dt);
};
void Thing::Update(float dt) {
    if (timer != Zero) {
        timer = timer - dt;
        if (timer <= Zero) {
            timer = 0.0f;
            Stop();
            b = 0;
            a = 0;
        }
    }
}