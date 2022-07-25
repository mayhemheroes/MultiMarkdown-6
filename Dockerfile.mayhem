FROM --platform=linux/amd64 ubuntu:20.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential git cmake

ADD . /repo
WORKDIR /repo

RUN make release
WORKDIR /repo/build
RUN make -j8

RUN mkdir -p /deps
RUN ldd /repo/build/multimarkdown | tr -s '[:blank:]' '\n' | grep '^/' | xargs -I % sh -c 'cp % /deps;'

FROM ubuntu:20.04 as package

COPY --from=builder /deps /deps
COPY --from=builder /repo/build/multimarkdown /repo/build/multimarkdown
ENV LD_LIBRARY_PATH=/deps
