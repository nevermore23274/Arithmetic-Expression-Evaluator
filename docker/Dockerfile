# Specifies base image
FROM ubuntu:20.04
# Timezone config
ENV DEBIAN_FRONTEND=noninteractive 
ENV TZ=America/New_York
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
# Install C++ tools
RUN apt-get update -y && apt-get install -y wget build-essential libssl-dev gdb pkg-config valgrind systemd-coredump
# Remove old version of CMAKE and install more current one
RUN apt remove --purge --auto-remove cmake -y
RUN wget https://github.com/Kitware/CMake/releases/download/v3.24.2/cmake-3.24.2.tar.gz
RUN tar -xzvf cmake-3.24.2.tar.gz
RUN cd cmake-3.24.2 && ./bootstrap && make -j$(nproc) && make install
RUN rm -rf cmake-3.24.2 && rm cmake-3.24.2.tar.gz
# Set the default working directory
WORKDIR /project2