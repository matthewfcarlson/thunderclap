// Same code shape as 0x002feb70 (propagated; names are from that function)
typedef unsigned int uint;
void __cdecl FUN_002feb70(uint* p, int n, int limit, uint value)
{
 int parent=(n-1)/2;
 if (limit < n) {
   do {
     uint x=p[parent];
     if (x >= value) break;
     p[n]=x; n=parent; parent=(n-1)/2;
   } while (limit < n);
 }
 p[n]=value;
}
