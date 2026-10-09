class C {
  public:
    int count;
    float data[1];
    bool target(float* p);
};
bool C::target(float* p) {
    int i = count - 1;
    if (i >= 0) {
        float* q = data + i * 4 + 1;
        do {
            float s = q[0] * p[1] + q[1] * p[2] + q[-1] * p[0];
            if (!(s <= -q[2]))
                return false;
            --i;
            q -= 4;
        } while (i >= 0);
    }
    return true;
}