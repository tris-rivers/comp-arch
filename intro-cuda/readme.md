# Intro to CUDA Sample Codes
This repository contains the code sample C++ function that can be run using different CUDA configurations. 
There are 4 different files containing this folder, with all the files implementing the same function: Linear Addition of two arrays with 1M elements:
- **`sample.cpp`**: C++ verson of the code
- **`sample_gpu.cu`**: CUDA version of the code, running only on 1 thread block with 1 core(thread).
- **`sample_gpu_thread.cu`**: CUDA version of the code, running only on 1 thread block with 256 core(threads).
- **`sample_gpu_sm.cu`**: CUDA version of the code, running only on multiple thread blocks each with multiple threads(32 threads per block).

### To run the c++ file:
`` $ g++ -pg <c++ file> -o <output> ``
example:
``$ g++ -pg sample.cpp -o sample ``
run the code using `$ ./sample`
alternatively, the `-pg` parameter prepares the code for profilling using **[gprof](https://www.thegeekstuff.com/2012/08/gprof-tutorial/)**.
you can run the gprof profiler using `$ gprof sample_cpu gmon.out > analysis.txt` after running the output.

### To run the CUDA file: 
`` $ nvcc <cuda file(.cu)> -o <output>  ``
example:
`` $ nvcc sample_gpu.cu -o sample_cuda ``
run the code using `$ ./sample_cuda `
profile the code using `$ nvprof ./sample_cuda`
