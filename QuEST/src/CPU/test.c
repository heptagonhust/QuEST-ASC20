#include <immintrin.h>
#include <stdio.h>

int main() {
  __m256d avxAR, avxAI, avxBR, avxBI, avxDataState, avxDataStateR, avxDataA,
      avxDataB, avxDataC, avxDataD;

  double storeData[4];

  avxAR = _mm256_set1_pd(2);
  avxAI = _mm256_set1_pd(3);
  avxBR = _mm256_set1_pd(4);
  avxBI = _mm256_set1_pd(5);

  double stateRealLo = 10;
  double stateRealUp = 100;
  double stateImagUp = 1000;
  double stateImagLo = 10000;

  avxDataState =
      _mm256_set_pd(stateRealLo, stateRealUp, stateImagUp, stateImagLo);
  avxDataStateR =
      _mm256_set_pd(stateImagLo, stateImagUp, stateRealUp, stateRealLo);

  avxDataA = _mm256_mul_pd(avxAR, avxDataState);
  _mm256_storeu_pd(storeData, avxDataA);
  printf("%lf,%lf,%lf,%lf \n", storeData[0], storeData[1], storeData[2],
         storeData[3]);

  avxDataB = _mm256_mul_pd(avxAI, avxDataStateR);
  _mm256_storeu_pd(storeData, avxDataB);
  printf("%lf,%lf,%lf,%lf \n", storeData[0], storeData[1], storeData[2],
         storeData[3]);

  avxDataC = _mm256_mul_pd(avxBR, avxDataState);
  _mm256_storeu_pd(storeData, avxDataC);
  printf("%lf,%lf,%lf,%lf \n", storeData[0], storeData[1], storeData[2],
         storeData[3]);

  avxDataD = _mm256_mul_pd(avxBI, avxDataStateR);
  _mm256_storeu_pd(storeData, avxDataD);
  printf("%lf,%lf,%lf,%lf \n", storeData[0], storeData[1], storeData[2],
         storeData[3]);

  avxDataA = _mm256_addsub_pd(avxDataA, avxDataB);
  _mm256_storeu_pd(storeData, avxDataA);
  printf("%lf,%lf,%lf,%lf \n", storeData[0], storeData[1], storeData[2],
         storeData[3]);
         

  avxDataC = _mm256_addsub_pd(avxDataC, avxDataD);
  _mm256_storeu_pd(storeData, avxDataC);
  printf("%lf,%lf,%lf,%lf \n", storeData[0], storeData[1], storeData[2],
         storeData[3]);



  avxDataD = _mm256_addsub_pd(_mm256_permute_pd(avxDataA, 0b1001),
                              _mm256_permute_pd(avxDataC, 0b0110));

  _mm256_storeu_pd(storeData, avxDataD);
  printf("%lf,%lf,%lf,%lf", storeData[0], storeData[1], storeData[2],
         storeData[3]);

  return 0;
}