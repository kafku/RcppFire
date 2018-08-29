# RcppFire
[![Stories in Ready](https://badge.waffle.io/kafku/RcppFire.svg?label=ready&title=Ready)](http://waffle.io/kafku/RcppFire)

R and Arrayfire via Rcpp

## Prerequisites

- R packages
 - Rcpp
- Arrayfire
- gcc (>= 4.8)

## Installation
```R
install.packages('devtools')
library(devtools)
install_github(repo = 'kafku/RcppFire@develop')
```
If you want to try RcppFire with keeping your
local enviornment clean, then
```R
dev_mode(on = T)
install_github(repo = 'kafku/RcppFire@develop')
# do something with RcppFire
dev_mode(on = F)
```
RcppFire, with its default configuration, uses 
the CUDA version of Arrayfire. For using OpenCL or CPU version, 
invoke `install_github` with _--with-build-type_ argument.
```R
# using OpenCL version
install_github(repo = 'kafku/RcppFire@develop',
               args = c("--configure-args='--with-build-type=opencl'"))

# using CPU version
install_github(repo = 'kafku/RcppFire@develop',
               args = c("--configure-args='--with-build-type=cpu'"))
```

## Status

This package is not actively maintained now. See [RcppArrayFire](https://github.com/daqana/rcpparrayfire), which is a fork project of this package.

## Authors

Kazuki Fukui

## License

GPL (>= 2)
