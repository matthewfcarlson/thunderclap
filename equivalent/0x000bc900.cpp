// STATUS: equivalent (tools/equiv.py level 3: 95 inputs, branch coverage 2/2)
// FUN_000bc900 @ 0x000bc900
// cl-flags: /GS
typedef unsigned short WideChar;
extern "C" unsigned int __cdecl FUN_00294b80(const WideChar* text);
struct Entry_bc900 { WideChar text[64]; };
struct Object {
 char padding[0x1884]; Entry_bc900 entries[1];
 bool FUN_000b77c0(int key, WideChar* output, int capacity, int mode);
 int FUN_000bc900(WideChar* output, int position, int key, int entryIndex);
};
int Object::FUN_000bc900(WideChar* output, int position, int key, int entryIndex) {
 struct Workspace { WideChar buffer[64];  } workspace;
 if (!FUN_000b77c0(key, workspace.buffer, 64, 1)) { return 0; }
 output[position++] = 32; output[position++] = 32;
 const WideChar* text = entries[entryIndex].text;
 unsigned int count = FUN_00294b80(text);
 unsigned int bytes = count * 2;
 unsigned int* dest = reinterpret_cast<unsigned int*>(output + position);
 const unsigned int* src = reinterpret_cast<const unsigned int*>(text);
 for (unsigned int i = 0; i < (bytes >> 2); ++i) dest[i] = src[i];
 if (bytes & 2) output[position + (bytes >> 1) - 1] = text[(bytes >> 1) - 1];
 position += count; output[position++] = 32;
 count = FUN_00294b80(workspace.buffer);
 bytes = count * 2;
 dest = reinterpret_cast<unsigned int*>(output + position);
 src = reinterpret_cast<const unsigned int*>(workspace.buffer);
 for (unsigned int j = 0; j < (bytes >> 2); ++j) dest[j] = src[j];
 if (bytes & 2) output[position + (bytes >> 1) - 1] = workspace.buffer[(bytes >> 1) - 1];
 position += count; output[position] = 0;
  return position;
}
