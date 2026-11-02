// STATUS: equivalent (tools/equiv.py level 3: 2800 inputs, branch coverage 26/26)
// FUN_002d92c0 @ 0x002d92c0
struct RowInfo_2d92c0 {
 unsigned int width;
 unsigned int rowBytes;
 unsigned char type;
 unsigned char bitDepth;
 unsigned char channels;
 unsigned char pixelDepth;
};
extern "C" void __cdecl FUN_002d92c0(void * info, unsigned char* row) {
 unsigned int depth = ((RowInfo_2d92c0 *)info)->bitDepth;
 if (depth >= 8) return;
 unsigned int width = ((RowInfo_2d92c0 *)info)->width;
 if (width && (depth == 1 || depth == 2 || depth == 4)) {
  unsigned int perByte = 8 / depth;
  unsigned int last = width - 1;
  unsigned char* src = row + last / perByte;
  unsigned char* dst = row + last;
  unsigned int shift = (perByte - 1 - last % perByte) * depth;
  unsigned int mask = (1U << depth) - 1;
  unsigned int remaining = width;
  do {
   *dst = (unsigned char)((*src >> shift) & mask);
   if (shift == 8 - depth) { shift = 0; --src; }
   else shift += depth;
   --dst;
  } while (--remaining);
 }
 unsigned int channels = ((RowInfo_2d92c0 *)info)->channels;
 ((RowInfo_2d92c0 *)info)->bitDepth = 8;
 ((RowInfo_2d92c0 *)info)->pixelDepth = (unsigned char)(channels * 8);
 ((RowInfo_2d92c0 *)info)->rowBytes = channels * width;
}
