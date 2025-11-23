FROM rust:slim-trixie
RUN rustup target add x86_64-unknown-linux-musl && \
    apt update && \
    apt install -y musl-tools musl-dev && \
    update-ca-certificates
WORKDIR /build
COPY ./src ./src
COPY ./Cargo.lock .
COPY ./Cargo.toml .
RUN cargo build --target x86_64-unknown-linux-musl --release
RUN ls -ahl

FROM scratch
COPY --from=0 /build/target/x86_64-unknown-linux-musl/release/mdb_isready /mdb_isready
ENTRYPOINT ["/mdb_isready"]

