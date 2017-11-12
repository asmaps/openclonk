FROM ubuntu:16.04
MAINTAINER OpenClonk Dev Team

ENV DEBIAN_FRONTEND noninteractive
RUN apt-get update \
  && apt-get install -y --no-install-recommends git cmake build-essential \
       libpng-dev libjpeg-dev ninja-build libfreetype6-dev libglew-dev libreadline-dev \
       libsdl2-dev libqt5widgets5 qtbase5-dev libsdl2-mixer-dev libdw-dev \
  && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /opt/code
RUN mkdir /opt/dist
RUN mkdir /opt/cmake
RUN chown -R 1000:1000 /opt
USER 1000

WORKDIR /opt/code
RUN git clone git://git.openclonk.org/openclonk
WORKDIR /opt/cmake
RUN cmake /opt/code/openclonk -GNinja

VOLUME /opt/code
CMD ["ninja", "openclonk"]
