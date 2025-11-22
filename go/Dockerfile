FROM golang:1.25
WORKDIR /build
COPY . .
RUN CGO_ENABLED=0 GOOS=linux go build -o mdb_isready .

# FROM alpine
# FROM gcr.io/distroless/static
# FROM cgr.dev/chainguard/static
FROM scratch
COPY --from=0 /build .
ENTRYPOINT ["/mdb_isready"]
