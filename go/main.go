package main

import (
	"context"
	"encoding/json"
	"fmt"
	"os"
	"go.mongodb.org/mongo-driver/v2/bson"
	"go.mongodb.org/mongo-driver/v2/mongo"
	"go.mongodb.org/mongo-driver/v2/mongo/options"
)

func main() {
	uri := os.Args[1]
	client, err := mongo.Connect(options.Client().ApplyURI(uri))
	db := client.Database("admin")
	if err != nil {
		panic(err)
	}

	defer func() {
		if err := client.Disconnect(context.TODO()); err != nil {
			panic(err)
		}
	}()
	command := bson.D{{"hello", 1}}
	var result bson.M
	err = db.RunCommand(context.TODO(), command).Decode(&result)
	if err != nil {
		panic(err)
	}
	jsonData, err := json.MarshalIndent(result, "", "    ")
	if err != nil {
		panic(err)
	}
	fmt.Printf("%s\n", jsonData)
}

