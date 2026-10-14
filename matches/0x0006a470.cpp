struct CCameraDramaticTrack {
    char pad[0x60];
};
struct Sub_6a470 {
    void Init();
};
struct CTrack {
    void Finish();
};
extern int vCamera;
extern int vTrack;
void __fastcall Target(CCameraDramaticTrack* self) {
    *(int**)self = &vCamera;
    Sub_6a470* p = (Sub_6a470*)((char*)self + 0x60);
    int n = 8;
    do {
        p = (Sub_6a470*)((char*)p - 8);
        p->Init();
        --n;
    } while (n != 0);
    *(int**)self = &vTrack;
    ((CTrack*)self)->Finish();
}