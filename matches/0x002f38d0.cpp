class CollisionMesh {
  public:
    char pad[0x44];
    struct Data {
        char a[8];
        int* vertices;
        char b[12];
        unsigned short* indices;
    }* data;
    void vfunc_18(int, int*, int*, int*);
};
void CollisionMesh::vfunc_18(int n, int* a, int* b, int* c) {
    int off = (n * 3) * 8;
    unsigned short k = *(unsigned short*)((char*)data->indices + off + 16);
    int* p = data->vertices + k * 3;
    a[0] = p[0];
    a[1] = p[1];
    a[2] = p[2];
    k = *(unsigned short*)((char*)data->indices + off + 18);
    p = data->vertices + k * 3;
    b[0] = p[0];
    b[1] = p[1];
    b[2] = p[2];
    k = *(unsigned short*)((char*)data->indices + off + 20);
    p = data->vertices + k * 3;
    c[0] = p[0];
    c[1] = p[1];
    c[2] = p[2];
}