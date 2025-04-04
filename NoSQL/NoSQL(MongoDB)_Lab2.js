//1- Provide the MongoDB code for enforcing JSON schema validation when creating a collection named "employees" with required fdbields "name," "age" (min. 18), and "department" (limited to ["HR," "Engineering," "Finance"]).
db.createCollection("employees" , {validator:{
    $jsonSchema:{
        bsonType:"object",
        title:"Employee Object Validation",
        required:["name" , "age","department"],
        properties:{
            age:{minimum:18, description:"age must be at least 18."},
            department:{enum:["HR","Engineering","Finance"],description:"depatment must be from 'HR' or 'Engineering' or 'Finance'"}
        }
    }
}})


//2-Find documents where the "tags" field exists. 
db.inventory.find({"tags":{$exists:true}})


//3- Find documents where the "status" field has a value in [A, B] using both the `$in` , `$or` operators. 
db.inventory.find({"status":{$in:["A","B"]}})
db.inventory.find({$or:[{"status":"A"},{"status":"B"}]})


//4- Find documents where the "tags" field does not contain values "ssl" or "security." 
db.inventory.find({"tags":{$nin:["ssl","security"]}})


//5-Find documents where the "qty" field is equal to 85. 
db.inventory.find({"qty":{$eq:85}})


//6-Find documents where the "tags" array contains all of the values [ssl, security] using the `$all` operator.
db.inventory.find({"tags":{$all:["ssl","security"]}})


//7- Find documents where the "tags" array has a size of 3
db.inventory.find({"tags":{$size:3}})


//8- Find documents where the "tags" field is of type array. 
db.inventory.find({"tags":{$type:"array"}})


//9- Update the "item" field in the "paper" document, setting "size.uom" to "meter" and using the `$currentDate` operator. 

//A) Also, use the upsert option and change filter condition item:”paper”. 
db.inventory.updateOne({"item":"paper"},{$set:{"size.uom":"meter"} , $currentDate:{date:true} } , {upsert:true})
db.inventory.find({"item":"document"})
//B) Use the `$setOnInsert` operator.
db.inventory.updateOne({"item":"paper"},{$set:{"size.uom":"meter"} , $currentDate:{date:true} , $setOnInsert:{"name":"Adham"}}  , {upsert:true}) 

//C) Try `updateOne`, `updateMany`, and `replaceOne`.
db.inventory.updateMany({"item":"paper"},{$set:{"size.uom":"meter"} , $currentDate:{date:true} , $setOnInsert:{"name":"Adham"}}  , {upsert:true})
db.inventory.replaceOne({"item":"paper"},{"item":"document","size":{"uom":"cm"}})



//10- Insert a document with incorrect field names "neme" and "ege," then rename them to "name" and "age." 
db.inventory.insertOne({"neme":"Adham","ege":"25"})
db.inventory.find({"name":"Adham"})
db.inventory.updateOne({"neme":"Adham"},{$rename:{"neme":"name" , "ege":"age"}})


//11- Try to reset any document field using the `$unset` function. 
db.inventory.updateOne({"item":"paper"} , {$unset:{"size.uom":""}})
db.inventory.find({"item":"paper"})


//12- Try update operators like `$inc`, `$min`, `$max`, and `$mul` to modify document fields. 
db.inventory.updateOne({"item":"paper"} , {$inc:{"qty":10}})
db.inventory.updateOne({"item":"paper"} , {$min:{"qty":10}})
db.inventory.updateOne({"item":"paper"} , {$max:{"qty":20}})
db.inventory.updateOne({"item":"paper"} , {$mul:{"qty":2}})