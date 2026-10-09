struct Helper { void Fin(); };
class CTrack { public: void Base(); };
class CKeyPoseTrack {
public:
    void Dtor();
    char pad[0x60];
};
void CKeyPoseTrack::Dtor() {
    *(void**)this = (void*)0x3fbb34;
    ((Helper*)((char*)this + 0x60))->Fin();
    ((Helper*)((char*)this + 0x10))->Fin();
    *(void**)this = (void*)0x3f98d0;
    ((CTrack*)this)->Base();
}
