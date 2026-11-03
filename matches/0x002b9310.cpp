#include "gen/owners.h"
struct Vector {
    float x, y, z;
};
struct Object {
    char pad[0x30];
    Vector position;
};
struct Matrix {
    float data[16];
    void FUN_0022b980();
    void FUN_0022cc90(Vector*);
};
struct Owner_2b9310 {
    char pad[0x40];
    Matrix transform;
    int FUN_002b8f60(int, Matrix*, int, Object*, int);
    int target(int, Object*, int, Object*, int);
};
int Owner_2b9310::target(int a, Object* from, int c, Object* to, int e) {
    Vector endpoint = to->position;
    Vector origin = from->position;
    Vector delta;
    delta.x = origin.x - endpoint.x;
    delta.y = origin.y - endpoint.y;
    delta.z = origin.z - endpoint.z;
    Matrix translation;
    translation.FUN_0022b980();
    translation.FUN_0022cc90(&delta);
    Matrix result;
    ((owners::Matrix_22ca90 *)&result)->FUN_0022ca90((const owners::Matrix_22ca90 *)(Matrix *)(&transform), (const owners::Matrix_22ca90 *)(Matrix *)(&translation));
    ((owners::Target_22be40 *)&result)->FUN_0022be40((const int *)(Vector *)(&origin));
    return FUN_002b8f60(a, &result, c, to, e);
}