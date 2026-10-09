class CEncounter {
  public:
    virtual void V();
    char pad[0x30 - 4];
    class Sub {
      public:
        int x;
        void Init();
    } sub;
    char pad2[0x52 - 0x34];
    unsigned short field52;
    void InitEncounter();
    CEncounter();
};
CEncounter::CEncounter() {
    sub.Init();
    field52 = 0;
    InitEncounter();
}