# Neural Network implementation using CUDA
This repository contains the neural network implementation using CUDA. This is only a **[multilayer perceptron](https://en.wikipedia.org/wiki/Multilayer_perceptron)** with 4 inputs containing 4 features on the data. This is only to simulate how a neural network is implemented using CUDA.
There are 2 different files containing this folder, one containing the C++ version and one is the CUDA version.
- **`perceptron.cpp`**: C++ verson of the MLP.
- **`perceptron.cu`**: CUDA version of the MLP. Matrix operations are parallelized through GPU.

### To run the c++ file:
``$ g++ -pg perceptron.cpp -o perceptron_cpu ``
run the code using `$ ./perceptron_cpu`
alternatively, the `-pg` parameter prepares the code for profilling using **[gprof](https://www.thegeekstuff.com/2012/08/gprof-tutorial/)**.

### To run the CUDA file: 
`` $ nvcc -arch=sm_50 -rdc=true perceptron.cu -o perceptron ``
The `-arch` argument specifies what NVIDIA virtual GPU architecture to use.
The `-rdc` enables the generation of relocatable device code which links the `__device__` functions.
To read more about the `-arch` and `-rdc` arguments, see [CUDA Toolkit Documentation](https://docs.nvidia.com/cuda/cuda-compiler-driver-nvcc/index.html#nvcc-command-options)
run the code using `$ ./perceptron`
profile the code using `$ nvprof ./perceptron
