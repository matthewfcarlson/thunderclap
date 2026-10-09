struct V {
    float v[6];
    void Merge(V*);
};
void V::Merge(V* p) {
    v[0] = (v[0] < p->v[0]) ? v[0] : p->v[0];
    v[1] = (v[1] < p->v[1]) ? v[1] : p->v[1];
    v[2] = (v[2] < p->v[2]) ? v[2] : p->v[2];
    v[3] = (v[3] < p->v[0]) ? p->v[0] : v[3];
    v[4] = (v[4] < p->v[1]) ? p->v[1] : v[4];
    v[5] = (v[5] < p->v[2]) ? p->v[2] : v[5];
}
