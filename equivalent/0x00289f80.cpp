// STATUS: equivalent (tools/equiv.py level 3: 2989 inputs, branch coverage 11/12, incomplete)
// FUN_00289f80 @ 0x00289f80
struct Table {
 char padding[16];
 int count;
 short* values;
 bool FUN_00289f80(float value, int* lower, int* upper);
};
bool Table::FUN_00289f80(float value, int* lower, int* upper) {
 short* data = values;
 if (!((float)data[0] < value)) { *upper = 0; *lower = 0; return false; }
 int n = count;
 if ((float)data[n-1] <= value) { *upper = n-1; *lower = n-1; return false; }
 unsigned int lo = 0, hi = n-1;
 for (;;) {
  unsigned int mid = (lo + hi) >> 1;
  float current = (float)data[mid];
  if (value >= current && (float)data[mid+1] > value) {
   *lower = mid;
   *upper = mid+1;
   return true;
  }
  if (current < value) lo = mid+1;
  else if (current > value) hi = mid-1;
 }
}
