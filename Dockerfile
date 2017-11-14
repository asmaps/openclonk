FROM ubuntu:16.04
MAINTAINER OpenClonk Dev Team

ENV DEBIAN_FRONTEND noninteractive
RUN apt-get update \
  && apt-get install -y --no-install-recommends git cmake build-essential \
       libpng-dev libjpeg-dev ninja-build libfreetype6-dev libglew-dev libreadline-dev \
       libsdl2-dev libqt5widgets5 qtbase5-dev libsdl2-mixer-dev libdw-dev dbus-x11 \
  && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /opt/code
RUN chown -R 1000:1000 /opt
RUN mkdir -p /home/.clonk
RUN chown -R 1000:1000 /home
ENV HOME=/home
USER 1000

COPY . /opt/code
WORKDIR /opt/code

VOLUME /opt/code
VOLUME /home
ENTRYPOINT ["/opt/code/docker_entrypoint.sh"]
CMD ["make"]
