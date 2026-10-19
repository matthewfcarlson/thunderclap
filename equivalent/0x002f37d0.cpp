// STATUS: equivalent (tools/equiv.py level 3: 13512 inputs, branch coverage 0/0)
// FUN_002f37d0 @ 0x002f37d0
// FUN_002f37d0 @ 0x002f37d0
struct Vec { float x,y,z; };
struct Temp { float x,y,z; char extra[4]; void FUN_0022dfe0(const Vec*,const Vec*,const Vec*); };
struct Indices { char pad[16]; unsigned short a,b,c; };
struct Buffer { char pad[8]; Vec* vertices; };
struct Object { char pad[0x44]; Buffer* buffer; Vec* FUN_002f37d0(Vec* result, const Indices* indices); };
Vec* Object::FUN_002f37d0(Vec* result, const Indices* indices)
{
    Temp temp;
    Vec* vertices = buffer->vertices;
    temp.FUN_0022dfe0(vertices + indices->a, vertices + indices->b, vertices + indices->c);
    result->x = temp.x;
    result->y = temp.y;
    result->z = temp.z;
    return result;
}
