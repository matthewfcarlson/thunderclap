struct Box { float v[6]; unsigned char Contains(Box* b); };
unsigned char Box::Contains(Box* b) {
    return b->v[3] >= v[0] && b->v[0] <= v[3] && b->v[4] >= v[1] && b->v[1] <= v[4] && b->v[5] >= v[2] && b->v[2] <= v[5];
}
