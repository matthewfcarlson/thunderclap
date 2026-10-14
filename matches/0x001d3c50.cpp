class Thing_1d3c50 {
  public:
    void Load(const char*, int);
    void Init();
};
void Thing_1d3c50::Init() {
    Load("init.lua", 0);
    Load("scripts/physics.lua", 0);
    Load("scripts/damage.lua", 0);
    Load("scripts/config.lua", 0);
}
