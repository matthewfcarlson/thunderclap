class V {
  public:
    float x, y, z;
    int Contains(V* other, float limit);
};
int V::Contains(V* other, float limit) {
    float d = x - other->x;
    *(int*)&d &= 0x7fffffff;
    if (d <= limit) {
        d = y - other->y;
        *(int*)&d &= 0x7fffffff;
        if (d <= limit) {
            d = z - other->z;
            *(int*)&d &= 0x7fffffff;
            if (d <= limit)
                return 1;
        }
    }
    return 0;
}