class Game_bfbe0 {
  public:
    char pad[0x1880];
    float timer;
    bool Check(int, int);
    void Tick(void*, float);
};
class Manager_bfbe0 {
  public:
    void Start();
};
class Factory_bfbe0 {
  public:
    Game_bfbe0* Create(const char*, int, int);
};
void Game_bfbe0::Tick(void* arg, float dt) {
    timer += dt;
    if (Check(0, 1))
        timer = 0.0f;
    if (timer >= 66.6f) {
        Game_bfbe0* p = ((Factory_bfbe0*)arg)->Create("attract", 1000, 1);
        ((Manager_bfbe0*)p)->Start();
        timer = 0.0f;
    }
}