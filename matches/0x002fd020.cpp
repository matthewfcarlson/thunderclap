struct Transform {
    char pad0[4];
    float m04, m08, m0c, m10, m14, m18;
    void Apply(float*, float*);
};
void Transform::Apply(float* v, float* out) {
    out[0] = m04 * v[0] + m08 * v[1] + m0c * v[2];
    out[1] = m10 * v[1] + m14 * v[2] + m08 * v[0];
    out[2] = m18 * v[2] + m0c * v[0] + m14 * v[1];
}