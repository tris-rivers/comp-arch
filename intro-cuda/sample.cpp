#include <iostream>
#include <math.h>
#include <time.h>

// function to add the elements of two arrays
void add(int n, float *x, float *y)
{
  for (int i = 0; i < n; i++)
      y[i] = x[i] + y[i];
}

int main(void)
{
  int N = 1<<20; // 1M elements


  //start time for initializing arrays
  clock_t start = clock();

  float *x = new float[N];
  float *y = new float[N];

  // initialize x and y arrays on the host
  for (int i = 0; i < N; i++) {
    x[i] = 1.0f;
    y[i] = 2.0f;
  }
  // end time for initializing arrays
  clock_t end = clock();
  double elapsed_time = (end-start)/(double)CLOCKS_PER_SEC ;
  std::cout << "Initialize Array Compute Time: " << elapsed_time << std::endl;


  //start time for add
  start = clock();
  // Run kernel on 1M elements on the CPU
  add(N, x, y);
  // end time for initializing arrays
  end = clock();

  elapsed_time = (end-start)/(double)CLOCKS_PER_SEC ;
  std::cout << "Add 1M Arrays on CPU Compute Time: " << elapsed_time << std::endl;

  // Check for errors (all values should be 3.0f)
  float maxError = 0.0f;
  for (int i = 0; i < N; i++)
    maxError = fmax(maxError, fabs(y[i]-3.0f));
  std::cout << "Max error: " << maxError << std::endl;

  // Free memory
  delete [] x;
  delete [] y;

  return 0;
}



