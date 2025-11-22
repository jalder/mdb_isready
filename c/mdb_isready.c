#include <bson/bson.h>
#include <mongoc/mongoc.h>
#include <stdio.h>
int
main (int argc, char *argv[])
{
    bson_t reply;
    bson_error_t error;
    mongoc_init ();    
    mongoc_client_t *client = mongoc_client_new (argv[1]);
    if (!client) {
        fprintf(stderr, "Failed to create client.\n");
        return EXIT_FAILURE;
    }
    mongoc_client_set_appname(client, "mdb_isready");
    bson_t *command = BCON_NEW("hello", BCON_INT32(1));

    if (mongoc_client_command_simple(client, "admin", command, NULL, &reply, &error)) {
        char *str = bson_as_relaxed_extended_json(&reply, NULL);
        printf("%s\n", str);
        bson_free(str);
    } else {
        fprintf(stderr, "%s\n", error.message);
        return EXIT_FAILURE;
    }

    bson_destroy(command);
    bson_destroy(&reply);
    mongoc_client_destroy(client);
    mongoc_cleanup();

    return EXIT_SUCCESS;
}
