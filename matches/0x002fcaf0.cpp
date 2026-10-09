class V {
  public:
    float a;
    float b;
    float c;
    float d;
    float e;
    float f;
    float g;
    void Add(V*);
};
void V::Add(V* p) {
    b += p->b;
    c += p->c;
    d += p->d;
    e += p->e;
    f += p->f;
    g += p->g;
}