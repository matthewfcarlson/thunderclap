class Game {
  public:
    char pad[0x1880];
    float timer;
    bool Check(int, int);
    void Tick(void*, float);
};
class Manager {
  public:
    void Start();
};
class Factory {
  public:
    Game* Create(const char*, int, int);
};
void Game::Tick(void* arg, float dt) {
    timer += dt;
    if (Check(0, 1))
        timer = 0.0f;
    if (timer >= 66.6f) {
        Game* p = ((Factory*)arg)->Create("attract", 1000, 1);
        ((Manager*)p)->Start();
        timer = 0.0f;
    }
}