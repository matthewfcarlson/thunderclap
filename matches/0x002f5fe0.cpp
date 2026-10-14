struct Manager_2f5fe0 {
    void Read(float*, int, int, int);
};
struct Owner_2f5fe0 {
    char pad[0x284];
    Manager_2f5fe0* mgr;
};
void __cdecl Target(Owner_2f5fe0* owner, float* dst) {
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