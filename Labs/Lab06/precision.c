

/*
  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
  * IN NO EVENT SHALL BUCKNELL UNIVERSITY BE LIABLE FOR ANY CLAIM, DAMAGES
  * OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
  * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
  */
 
 #include <stdio.h>
 #include <stdint.h>
 
 float one_half_single(void){
   /*
   This function creates and returns a float with the value 0.5
   You cannot just "return 0.5;"!
 
   The 32-bit value 0x3f000000 is the value of 0.5 in IEEE 754.
 
   If we use an array to access the bytes, we have to return
   it in reverse order. Since the array is stored in little-endian
   byte order, the most significant bits of the float are in index [3]!
   +-------+-------+-------+-------+
   |  [0]  |  [1]  |  [2]  |  [3]  | Memory byte offset
   +-------+-------+-------+-------+
   |  7-0  |  15-8 | 23-16 | 31-24 | Bits (IEEE single)
   +-------+-------+-------+-------+
   */
   unsigned char val[4] = {0, 0, 0, 0x3f};
   return *(float*)val;
 }
 double one_half_double(void){
   /*
   Use an approach similar to one_half_single but now return
   the double precision IEEE 754 value for 0.5 (8 bytes).
   */
     unsigned char val[8] = {0,0,0,0,0,0,0xe0,0x3f};
   return *(double*)val;
 }

 /*-----------------------------------*/

unsigned f2u(float f){
  union {
    unsigned u;
    float f;
  } v;
  v.f = f;
  return v.u;
}
unsigned long long d2u(double f){
  union {
    unsigned long long u;
    double f;
  } v;
  v.f = f;
  return v.u;
}

float u2f(unsigned d){
  union {
      unsigned u;
      float f;
  } v;
  v.u = d;
  return v.f;
}
double u2d(unsigned long long d){
  union {
      unsigned long long u;
      double f;
  } v;
  v.u = d;
  return v.f;
}


void inspect_float(float f)
{
 unsigned q = f2u(f);
 // TODO replace the zeros in the next three lines
 // with the appropriate values extracted from
 // q using bit shifting and masking
 int sign = (q>>31)&1;
 int exp = (q>>23)&0xff;
 int frac = q&0x7fffff;
 // do not change the printf!
 printf("Inspecting single % e, sign = %d, biased exponent = 0x%x, fraction = 0x%06x\n",
   f, sign, exp, frac);
}


void inspect_double(double f)
{
 unsigned long long q = d2u(f);
 // TODO replace the zeros in the next three lines
 // with the appropriate values extracted from
 // q using bit shifting and masking
 int sign = (q>>63)&1;
 int exp = (q>>52)&0x7ff;
 unsigned long long frac = q&0xfffffffffffff;
 // do not change the printf!
 printf("Inspecting double % le, sign = %d, biased exponent = 0x%x, fraction = 0x%013llx\n",
   f, sign, exp, frac);
}

float next_float(float f) {
   return u2f(f2u(f)+1);
}


int main()
{
    float f = 7.753e9;
    inspect_float(f);
    printf("next_float(%1.23f) == %1.23f\n",
      f,
      next_float(f));
    inspect_float(next_float(f));//1.00000011920928955078125
    /*
     *Floating point precision, as the numbers go from small to large, increase the gaps between each value that can be correctly represented with precision. This is because these larger values are more likely to be represented with exponential bits as well, making each increment to the end of the mantissa have a larger 'jump' between values.
     * */
    return 0;
}
 
