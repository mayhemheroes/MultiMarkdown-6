FROM --platform=linux/amd64 ubuntu:20.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential git cmake clang

COPY . /repo
WORKDIR /repo

RUN make release
WORKDIR /repo/build
RUN make -j8
RUN clang++ /repo/mayhem/fuzz_clean_string.cpp /repo/build/libMultiMarkdown.a -fsanitize=fuzzer,address -o /fuzz

FROM ubuntu:20.04 as package
COPY --from=builder /repo/build/multimarkdown /
COPY --from=builder /fuzz /fuzz_clean_string
