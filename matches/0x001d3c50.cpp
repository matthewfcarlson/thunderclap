class Thing {
  public:
    void Load(const char*, int);
    void Init();
};
void Thing::Init() {
    Load("init.lua", 0);
    Load("scripts/physics.lua", 0);
    Load("scripts/damage.lua", 0);
    Load("scripts/config.lua", 0);
}
