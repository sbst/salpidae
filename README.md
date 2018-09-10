# salpidae
## Overview
Generate signature for input file.

CRC32 hash is generating for every block.
All signatures collects in output file.

Block size set in arguments, 1 MB by default.
Hash for each block calculates in separate thread.

## Build

Linux:
```bash
$ git pull git@github.com:sbst/salpidae.git
$ mkdir ./salpidae/Build && cd ./salpidae/Build
$ cmake ../ && cmake --build ./
```

## Start

Linux:
```bash
$ ./Sources/salpidae -i ../Files/example -o ../Files/out -b 5
salpidae: Open input file: ../Files/example...
salpidae: Open output file: ../Files/out...
salpidae: Seeding...
salpidae: Clear...
salpidae: Done

$ cat ../Files/out 
165AE3A3
```

Verified in Ubuntu 16.04 LTS, 4.4.0-134 kernel