struct Manager {
    void Read(float*, int, int, int);
};
struct Owner {
    char pad[0x284];
    Manager* mgr;
};
void __cdecl Target(Owner* owner, float* dst) {
    float value;
    owner->mgr->Read(&value, 1, 4, 1);
    dst[1] = value;
    owner->mgr->Read(&value, 1, 4, 1);
    dst[2] = value;
    owner->mgr->Read(&value, 1, 4, 1);
    dst[3] = value;
    owner->mgr->Read(&value, 1, 4, 1);
    dst[4] = value;
    owner->mgr->Read(&value, 1, 4, 1);
    dst[5] = value;
    owner->mgr->Read(&value, 1, 4, 1);
    dst[6] = value;
}