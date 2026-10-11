extern "C" char DAT_00428e80[];
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
    *(int*)this = ((int)DAT_00428e80);
    ((SubA*)((char*)this + 0x20))->A();
    ((SubB*)((char*)this + 0x14))->B();
    Fin();
}
