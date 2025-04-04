//1- Create new  
//a) Database named Demo. 
//b) collections named trainningCenter1 , trainningCenter2.  
use demo
db.createCollection("trainingCenter1")
db.createCollection("trainingCenter2")


//2- Insert documents into trainningCenter1 collection contains _id , name as firstName lastName , age , address as array , status 
//   Using Variable (Array Data) and insert ONE 

var Data = [{
    _id: 1,
    name: { firstName: "Adham", lastName: "Assy" },
    age: 25,
    address: ["Cairo", "Egypt"],
    status: "Active"
},
{   _id: 2,
    name: { firstName: "Ayman", lastName: "Ashraf" },
    age: 35,
    address: ["Alexandria", "Egypt"],
    status: "Active"
},
{
    _id: 3,
    name: { firstName: "Fawzy", lastName: "Abbas" },
    age: 40,
    address: ["Mansoura", "Egypt"],
    status: "Active"
},
{
    _id: 4,
    name: { firstName: "Merna", lastName: "Ahmed" },
    age: 20,
    address: ["Cairo", "Egypt"],
    status: "not_active"
},
{
    _id: 5,
    name: { firstName: "Mona", lastName: "Zaki" },
    age: 45,
    address: ["Cairo", "Egypt"],
    status: "not_active"
}]
db.trainingCenter1.insertOne(Data)

//3- Insert documents into trainningCenter2 collection  
//   Using Same Variable (Array Data) with same data and insert MANY 
db.trainingCenter2.insertMany(Data)

db.trainingCenter1.find({})
db.trainingCenter2.find({})

//4- Use find. explain function (find by age field) and mention scanning type 
db.trainingCenter2.find({age:25}).explain() // --> COLLSCAN


//5- Create index on created collection named it “IX_age” on age field  
db.trainingCenter2.createIndex({ age: 1 }, { name: "IX_age" })

//6- Use find. explain view winning plan for index created (find by age field) and mention scanning type 
db.trainingCenter2.find({age:25}).explain() // --> IXScan

//7- Create index on created collection named it “compound” on firstNsme and lastName 

//   Try find().explain before create index and mention scanning type 
db.trainingCenter2.find({ "name.firstName": "Adham", "name.lastName": "Assy"}).explain()   // --> COLLScan
db.trainingCenter2.createIndex({ "name.firstName": 1 , "name.lastName": 1 }, { name: "compound" })

//   Try find().explain after create index and mention scanning type 
db.trainingCenter2.find({ "name.firstName": "Adham", "name.lastName": "Assy"}).explain()  // --> IXScan



//8- Try to delete from your collection where _id = 5 [insert it if not exists] 
db.trainingCenter2.deleteOne({_id:5})

//9-Delete all documents from the trainingCenter collection. 
db.trainingCenter2.deleteMany({})

//10- Drop the database and confirm its removal. Which command do you use to ensure the deletion? 
db.dropDatabase()
show databases

//11- Backup your Labs database (Mongo_ITI)  
db.serverCmdLineOpts()
//  --> mongodump --db staff --out "D:\iti\NoSQL(MongoDB)\AA"
 
//12- Restore the taken back-up by new DB name Called Mongo_ITI_New 
//  --> mongorestore --db New_staff --dir "D:\iti\NoSQL(MongoDB)\AA\staff"



