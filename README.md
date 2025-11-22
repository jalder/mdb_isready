# mdb_isready

A lightweight basic health and readiness check for MongoDB

## Usage

```
mdb_isready {mongodb-uri}
```

## Builds

### C Implementation

In the `c` directory is source for the container build of mdb_isready and non-static builds of mdb_isready.

Why? Smaller is better. (Not really, the image is actually bigger than go+scratch.  I also copied in libs wrecklessly from another base, please do not run this C implementation in an environment that you care about.)

### Go Implementation

In the `go` directory is the source for the general purpose arm64 and amd64 solution of mdb_isready.

Why? Easier build solution.  Relatively small container size using scratch, ~13MB.

### Rust Implementation

Sure, why not.  We have this too.

## Example Usage


### Go Implementation
```

## Connect Refused

jak@localhost:~/Repositories/mdb_isready$ docker run --net=host mdb_isready:go "mongodb://localhost:27018/?connectTimeoutMS=2000&serverSelectionTimeoutMS=2000"
panic: server selection error: context deadline exceeded, current topology: { Type: Unknown, Servers: [{ Addr: localhost:27018, Type: Unknown, Last error: dial tcp [::1]:27018: connect: connection refused }, ] }

goroutine 1 [running]:
main.main()
	/build/main.go:30 +0x31c
jak@localhost:~/Repositories/mdb_isready$ echo $?
2



## Standalone hello

jak@localhost:~/Repositories/mdb_isready$ docker run --net=host mdb_isready:go "mongodb://localhost:27017/?connectTimeoutMS=2000&serverSelectionTimeoutMS=2000"
{
    "connectionId": 36,
    "isWritablePrimary": true,
    "localTime": "2025-11-22T05:13:24.012Z",
    "logicalSessionTimeoutMinutes": 30,
    "maxBsonObjectSize": 16777216,
    "maxMessageSizeBytes": 48000000,
    "maxWireVersion": 13,
    "maxWriteBatchSize": 100000,
    "minWireVersion": 0,
    "ok": 1,
    "readOnly": false,
    "topologyVersion": {
        "processId": "691e688c4e0f6ac809353ce0",
        "counter": 0
    }
}
jak@localhost:~/Repositories/mdb_isready$ echo $?
0
jak@localhost:~/Repositories/mdb_isready$ 
```

### C Implementation
```
## Standalone hello

jak@localhost:~/Repositories/mdb_isready/c$ docker run --net=host mdb_isready:c "mongodb://localhost:27017/?connectTimeoutMS=2000&serverSelectionTimeoutMS=2000"
{ "isWritablePrimary" : true, "topologyVersion" : { "processId" : { "$oid" : "691e688c4e0f6ac809353ce0" }, "counter" : 0 }, "maxBsonObjectSize" : 16777216, "maxMessageSizeBytes" : 48000000, "maxWriteBatchSize" : 100000, "localTime" : { "$date" : "2025-11-22T05:16:50.381Z" }, "logicalSessionTimeoutMinutes" : 30, "connectionId" : 38, "minWireVersion" : 0, "maxWireVersion" : 13, "readOnly" : false, "ok" : 1.0 }
jak@localhost:~/Repositories/mdb_isready/c$ echo $?
0

## Connect Refused

jak@localhost:~/Repositories/mdb_isready/c$ docker run --net=host mdb_isready:c "mongodb://localhost:27018/?connectTimeoutMS=2000&serverSelectionTimeoutMS=2000"
No suitable servers found (`serverSelectionTryOnce` set): [connection refused calling hello on 'localhost:27018']
jak@localhost:~/Repositories/mdb_isready/c$ echo $?
1
jak@localhost:~/Repositories/mdb_isready/c$ 
```
