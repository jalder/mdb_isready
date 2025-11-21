# mdb_isready

A lightweight basic health and readiness check for MongoDB

## Usage

```
mdb_isready {mongodb-uri}
```

## Builds

### C Implementation

In the `c` directory is source for the container build of mdb_isready and non-static builds of mdb_isready.

Why? Smaller is better.

### Go Implementation

In the `go` directory is the source for the general purpose arm64 and amd64 solution of mdb_isready.

Why? Easier build solution.


