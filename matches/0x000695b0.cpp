extern "C" char DAT_003f98d0[];
extern "C" char DAT_003fbb34[];
struct Helper {
    void Fin();
};
class CTrack {
  public:
    void Base();
};
class CKeyPoseTrack {
  public:
    void Dtor();
    char pad[0x60];
};
void CKeyPoseTrack::Dtor() {
    *(void**)this = (void*)((int)DAT_003fbb34);
    ((Helper*)((char*)this + 0x60))->Fin();
    ((Helper*)((char*)this + 0x10))->Fin();
    *(void**)this = (void*)((int)DAT_003f98d0);
    ((CTrack*)this)->Base();
}
