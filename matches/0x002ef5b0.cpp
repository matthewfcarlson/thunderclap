struct Vec_2ef5b0 {
    float x, y, z;
};
struct Matrix {
    float m[16];
    void FUN_0022cdb0();
    void FUN_0022c2b0(const Vec_2ef5b0* input, Vec_2ef5b0* output);
};
struct Position_2ef5b0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Vec_2ef5b0* slot4();
    char pad[0x15];
    unsigned char dirty;
};
struct Node {
    char pad0[0x20];
    Position_2ef5b0* position;
    char pad1[0x44];
    unsigned char dirty;
};
struct Object {
    char pad[0x74];
    Node* node;
    void FUN_002ef5b0(const Matrix* first, Matrix* second);
};
void Object::FUN_002ef5b0(const Matrix* first, Matrix* second) {
    Matrix inverse = *first;
    inverse.FUN_0022cdb0();
    Vec_2ef5b0 intermediate, delta;
    inverse.FUN_0022c2b0(node->position->slot4(), &intermediate);
    second->FUN_0022c2b0(&intermediate, &delta);
    Vec_2ef5b0* original = node->position->slot4();
    Node* current = node;
    delta.x = delta.x - original->x;
    delta.y = delta.y - original->y;
    delta.z = delta.z - original->z;
    current->dirty = 1;
    Vec_2ef5b0* result = current->position->slot4();
    result->x = delta.x + result->x;
    result->y = delta.y + result->y;
    result->z = delta.z + result->z;
    current->position->dirty = 0;
}
