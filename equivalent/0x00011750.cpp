// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00011750 @ 0x00011750
struct Color_11750 {
 unsigned int value;
 void FUN_00011750(unsigned int from, unsigned int to, float amount);
};
void Color_11750::FUN_00011750(unsigned int from, unsigned int to, float amount) {
 int red = (from >> 16) & 255;
 int green = (from >> 8) & 255;
 int alpha = from >> 24;
 int blue = from & 255;
 unsigned int result = (unsigned int)(red + (int)(((int)((to >> 16) & 255) - red) * (double)amount)) << 16;
 result |= (unsigned int)(green + (int)(((int)((to >> 8) & 255) - green) * (double)amount)) << 8;
 result |= (unsigned int)(alpha + (int)(((int)(to >> 24) - alpha) * (double)amount)) << 24;
 result |= (unsigned int)(blue + (int)(((int)(to & 255) - blue) * (double)amount));
 value = result;
}