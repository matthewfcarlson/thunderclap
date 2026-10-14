class Box_1acb90 {
  public:
    float lo[3];
    float hi[3];
    unsigned char Contains(const float* p);
};
unsigned char Box_1acb90::Contains(const float* p) {
    if (p[0] >= lo[0] && p[0] <= hi[0] && p[1] >= lo[1] && p[1] <= hi[1] && p[2] >= lo[2] && p[2] <= hi[2])
        return 1;
    return 0;
}