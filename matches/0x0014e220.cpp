struct Track_14e220 {
    int vptr;
    Track_14e220();
};
struct HealthTrack_14e220 : Track_14e220 {
    char pad[8];
    int m0c;
    int m10;
    char m14, m15, m16;
    HealthTrack_14e220();
};
HealthTrack_14e220::HealthTrack_14e220() : Track_14e220() {
    m0c = 0;
    m10 = 0;
    m14 = 0;
    m15 = 0;
    m16 = 0;
    vptr = 0x414420;
}
