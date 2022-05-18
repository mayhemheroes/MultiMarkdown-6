FROM --platform=linux/amd64 ubuntu:20.04

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential git cmake

ADD . /repo
WORKDIR /repo

RUN make release
WORKDIR /repo/build
RUN make -j8
