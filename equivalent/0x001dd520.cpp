// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001dd520 @ 0x001dd520
struct Matrix { unsigned int words[16]; void FUN_0022b980(); };
struct Rotation_1dd520 { unsigned int words[4]; void FUN_0022b650(Matrix*); };
struct Orientation_1dd520 { unsigned int words[2]; void FUN_001db820(Rotation_1dd520*); };
struct Object { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual Matrix* v15(); };
struct Entry_1dd520 { char pad[16]; Orientation_1dd520 orientation; Object* object; char pad2[6]; short type; char pad3[4]; };
struct Type { unsigned int position[3]; unsigned int unused; unsigned char flags; char pad[3]; };
struct Manager_1dd520 { char pad[0x608]; Entry_1dd520 entries[2048]; Type types[1]; bool target(int index, Matrix* out); };
bool Manager_1dd520::target(int index, Matrix* out) { if (index < 0 || index >= 2048) return false; Entry_1dd520* entry = &entries[index]; Type* type = &types[entry->type]; if ((type->flags & 1) && entry->object) { Matrix* source = entry->object->v15(); for (int i=0;i<16;++i) out->words[i]=source->words[i]; return true; } out->FUN_0022b980(); Rotation_1dd520 rotation; entry->orientation.FUN_001db820(&rotation); rotation.FUN_0022b650(out); out->words[12]=type->position[0]; out->words[13]=type->position[1]; out->words[14]=type->position[2]; return true; }