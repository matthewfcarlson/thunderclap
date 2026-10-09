struct SubA {
    void A();
};
struct SubB {
    void B();
};
struct SpawnTrack {
    void Fin();
    void Run();
};
void SpawnTrack::Run() {
    *(int*)this = 0x428e80;
    ((SubA*)((char*)this + 0x20))->A();
    ((SubB*)((char*)this + 0x14))->B();
    Fin();
}
