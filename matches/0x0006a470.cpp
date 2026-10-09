struct CCameraDramaticTrack {
    char pad[0x60];
};
struct Sub {
    void Init();
};
struct CTrack {
    void Finish();
};
extern int vCamera;
extern int vTrack;
void __fastcall Target(CCameraDramaticTrack* self) {
    *(int**)self = &vCamera;
    Sub* p = (Sub*)((char*)self + 0x60);
    int n = 8;
    do {
        p = (Sub*)((char*)p - 8);
        p->Init();
        --n;
    } while (n != 0);
    *(int**)self = &vTrack;
    ((CTrack*)self)->Finish();
}