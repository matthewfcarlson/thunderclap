extern "C" char DAT_003f9980[];
class Helper {
  public:
    void Init();
    void Finish();
};
class CGrappleSwapTrack {
  public:
    char pad[0x10];
    int member10, member14, member18;
    void Run();
};
void CGrappleSwapTrack::Run() {
    *(void**)this = (void*)((int)DAT_003f9980);
    ((Helper*)((char*)this + 0x18))->Init();
    ((Helper*)((char*)this + 0x10))->Init();
    ((Helper*)this)->Finish();
}