use mongodb::{
	bson::{doc},
	sync::{Client}
};
use std::env;
fn main() -> mongodb::error::Result<()> {
    let args: Vec<String> = env::args().collect();
    let uri = args[1].clone();
    let client = Client::with_uri_str(uri)?;
    let database = client.database("admin");
    let result = database.run_command(doc! { "hello": 1 }).run();
    println!("{:#?}",result);
    Ok(())
}
