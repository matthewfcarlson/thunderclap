struct Matrix {
    unsigned int words[16];
};
struct Object {
    void FUN_001d6b60(Matrix matrix, unsigned int option);
};
struct Rotation_1dd470 {
    unsigned int words[4];
    void FUN_0022b370(const Matrix*);
};
struct State_1dd470 {
    unsigned int words[2];
    void FUN_001db780(const Rotation_1dd470*);
};
struct Entry_1dd470 {
    char pad[16];
    State_1dd470 state;
    Object* object;
    char pad2[6];
    short stateIndex;
    char tail[4];
};
struct Position_1dd470 {
    unsigned int x, y, z;
    unsigned int other;
    unsigned char flags;
    char pad[3];
};
struct Manager_1dd470 {
    char pad[0x608];
    Entry_1dd470 entries[2048];
    Position_1dd470 positions[1];
    bool target(int index, const Matrix* matrix, unsigned int option);
};
bool Manager_1dd470::target(int index, const Matrix* matrix, unsigned int option) {
    if (index < 0 || index >= 2048)
        return false;
    Entry_1dd470* entry = &entries[index];
    Position_1dd470* position = &positions[entry->stateIndex];
    if ((position->flags & 1) && entry->object) {
        entry->object->FUN_001d6b60(*matrix, option);
        return true;
    }
    Rotation_1dd470 rotation;
    rotation.FUN_0022b370(matrix);
    entry->state.FUN_001db780(&rotation);
    position->x = matrix->words[12];
    position->y = matrix->words[13];
    position->z = matrix->words[14];
    return true;
}