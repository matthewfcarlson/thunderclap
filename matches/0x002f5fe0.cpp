struct Manager_2f5fe0 {
    void Read(float*, int, int, int);
};
struct Owner_2f5fe0 {
    char pad[0x284];
    Manager_2f5fe0* mgr;
};
extern "C" void __cdecl FUN_002f5fe0(void * owner, float* dst) {
    float value;
    ((Owner_2f5fe0 *)owner)->mgr->Read(&value, 1, 4, 1);
    dst[1] = value;
    ((Owner_2f5fe0 *)owner)->mgr->Read(&value, 1, 4, 1);
    dst[2] = value;
    ((Owner_2f5fe0 *)owner)->mgr->Read(&value, 1, 4, 1);
    dst[3] = value;
    ((Owner_2f5fe0 *)owner)->mgr->Read(&value, 1, 4, 1);
    dst[4] = value;
    ((Owner_2f5fe0 *)owner)->mgr->Read(&value, 1, 4, 1);
    dst[5] = value;
    ((Owner_2f5fe0 *)owner)->mgr->Read(&value, 1, 4, 1);
    dst[6] = value;
}