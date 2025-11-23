FROM debian:12 as build

RUN apt-get update -y
RUN apt-get install -y cmake gcc gcc-multilib
WORKDIR /build
COPY . .
RUN cmake -S. -Bcmake-build
RUN cmake --build cmake-build --target mdb_isready


#FROM gcr.io/distroless/static-debian12
#FROM debian:12
#FROM gcr.io/distroless/static
FROM scratch
COPY --from=build /build/cmake-build/mdb_isready /mdb_isready
ENTRYPOINT ["/mdb_isready"]
