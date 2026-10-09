struct V {
    int pad;
    float x1, x2, x3, x4, x5, x6;
    void Add(V*, V*);
};
void V::Add(V* a, V* b) {
    x1 = a->x1 + b->x1;
    x2 = a->x2 + b->x2;
    x3 = a->x3 + b->x3;
    x4 = a->x4 + b->x4;
    x5 = a->x5 + b->x5;
    x6 = a->x6 + b->x6;
}