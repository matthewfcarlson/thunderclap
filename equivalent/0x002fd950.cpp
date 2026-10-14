// STATUS: equivalent (tools/equiv.py level 3: 2979 inputs, branch coverage 8/8)
// FUN_002fd950 @ 0x002fd950
struct CountSource { int FUN_0030f450(); };
struct Matrix { unsigned int words[16]; };
struct Transform_2fd950 { Matrix* FUN_0030f100(); };
struct Node { Transform_2fd950* FUN_0030edf0(); };
struct Entry_2fd950 {
 Node* node;
 unsigned int first[3];
 unsigned int second[3];
 unsigned char reset;
 char padding[3];
 Matrix matrix;
 float value;
};
struct Owner_2fd950 {
 char padding[0x88];
 CountSource* source;
 Entry_2fd950* entries;
 void FUN_002fd950(float value);
};
void Owner_2fd950::FUN_002fd950(float value) {
 if (!source) return;
 int index = 0;
 if (source->FUN_0030f450() <= 0) return;
 do {
  Entry_2fd950* entry = entries + index;
  if (value == 0.0f) {
   entry->first[2] = 0;
   entry->first[1] = 0;
   entry->first[0] = 0;
   entry->second[2] = 0;
   entry->second[1] = 0;
   entry->second[0] = 0;
   entry->reset = 1;
  } else {
   entry->value = value;
   Transform_2fd950* transform = entry->node->FUN_0030edf0();
   Matrix* matrix = transform->FUN_0030f100();
   for (int j = 0; j < 16; ++j) entry->matrix.words[j] = matrix->words[j];
   entry->reset = 0;
  }
  ++index;
 } while (index < source->FUN_0030f450());
}