Example of [OSS-Fuzz ideal integration](https://google.github.io/oss-fuzz/advanced-topics/ideal-integration/).

This directory contains an example software project that has most of the traits of [ideal](https://google.github.io/oss-fuzz/advanced-topics/ideal-integration/) support for fuzzing. 

## Files in my-api-repo
Imagine that these files reside in your project's repository:

* [calculactor.h](calculator.hpp): and [calculator.cpp](calculator.cpp) implement the calculator functinality we want to test/fuzz. The function `calculator::eval()` inside [calculator.cpp](calculator.cpp) contains a bug. (Find it!)
* [fuzz_calculator.cpp](fuzz_calculator.cpp): is a [fuzz target](http://libfuzzer.info/#fuzz-target) for `calculator::eval()`.
* [Makefile](Makefile): is a build file (the same can be done with other build systems):
  * accepts external compiler flags via `$CC`, `$CXX`, `$CFLAGS`, `$CXXFLAGS`
  * accepts external fuzzing engine via `$LIB_FUZZING_ENGINE`, by default uses [standalone_fuzz_target_runner.cpp](standalone_fuzz_target_runner.cpp)
  * builds the fuzz target(s) and their corpus archive(s)
  * `make check` executes [fuzz_calculator.cpp](fuzz_calculator.cpp) on [`do_stuff_test_data/*`](do_stuff_test_data), thus ensures that the fuzz target is up to date and uses it as a regression test.
* [standalone_fuzz_target_runner.cpp](standalone_fuzz_target_runner.cpp): is a simple standalone runner for fuzz targets. You may use it to execute a fuzz target on given files w/o having to link in libFuzzer or other fuzzing engine.

## Files in OSS-Fuzz repository
* [oss-fuzz/projects/example](..)
  * [Dockerfile](../Dockerfile): sets up the build environment
  * [build.sh](../build.sh): builds the fuzz target(s). The smaller this file the better (most of the logic should be inside the project's build system)

