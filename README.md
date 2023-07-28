# Arithmetic-Expression-Evaluator

# General Usage
- From the root directory you'll run:
```
docker build -t project2:latest -f docker/Dockerfile .
```
- Then you'll run:
```
docker run --name project2 -v <location_to_root_folder>:/project2 -it project2
```
- Once inside container and ready to build:
```
mkdir build && cd build
```
```
make
```
```
./project2
```
