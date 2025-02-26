import json
import time
import os
import re
import Main_Menu




class User :
    

    def __init__(self,Fname,Lname,Email,Password,Confirm_pass,Mobile_no):
        
        self.Fname=Fname
        self.Lname=Lname
        self.Email=Email
        self.Password=Password
        self.Confirm_pass=Confirm_pass
        self.Mobile_no=Mobile_no
    


def validate_mail(email):
    
     regex = r'\b[A-Za-z0-9._]+@[A-Za-z0-9.-]+\.[A-Z|a-z]{2,7}\b'
     valid_email = re.match(regex, email)
     return valid_email
              
        

 
def validate_pass(password):
     
     pattern = re.compile(r"^(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*[!@#$%^&*])[A-Za-z0-9!@#$%^&*]{8,}$")
     valid_password= pattern.match(password)
     return valid_password
     
         
          


def confirm_pass(confirm , password):
     if confirm == password :
         print("* Password confirmed. *")
         return True
     else:
        print("* Password doesn't match , pls try again *")
        return False 


def validate_mobile(mobile):
     
     pattern = re.compile(r"^01[0-2,5]{1}[0-9]{8}$")
     valid_phone= pattern.match(mobile)
     return valid_phone
    
        
     


def regestration_in_json(user):
    
     try:
          opening = open("myfile.json" , "r")
          json_list = json.load(opening)
          opening.close()
     except FileNotFoundError:
               json_list=[]
         
     json_list.append(user.__dict__)

     
     json_file = open("myfile.json" , "w")
     data = json.dumps(json_list , indent=4) 
     json_file.write(data)
     json_file.close()




def register():
     os.system('cls')
     print("--------- REGISTRATION --------")
     while True :
          Fname=input("Enter your first name: ").strip().capitalize()
          if Fname == "" or Fname.isalpha == False or len(Fname) < 3  :
               print("* INVALID FIRST NAME , TRY AGAIN *")
               time.sleep(2)
               register()
          else:
               break
     
     while True:
          os.system('cls')
          print("--------- REGISTRATION --------")
          print("Enter your first name : " , Fname)
          Lname=input("Enter your last name: ").strip().capitalize()
          if Lname == "" or Lname.isalpha() == False or len(Lname) < 3  :
               print("* INVALID LAST NAME , TRY AGAIN *")
               time.sleep(2)
          else:
               break
     while True :
          Email=input("Enter your email: ").lower()
          if validate_mail(Email) :
               break 
          else:
               print("* Invalid Email ,please try again .. *")
               time.sleep(2)
     while True : 
          Password=input("Enter your password: ")
          if validate_pass(Password) :
                break
          else:
               print("* Invalid Password ,please try again .. *")
               time.sleep(2)
            
     while True : 
          Confirm_pass=input("Re-enter your password: ")
          if confirm_pass(Confirm_pass , Password) :
               break
          
     while True :
          Mobile_no=input("Enter your mobile number : ")
          if validate_mobile(Mobile_no) :
               break
          else:
               print("* Invalid mobile number , please try again .. *")
               time.sleep(2)
     print("* Registration Completed .. *")
     
     user = User(Fname, Lname, Email, Password, Confirm_pass, Mobile_no)
     regestration_in_json(user)


def login():
     email=""
     while True :
          print("----------- LOGIN IN ------------")
          email=input("Enter your email : ")
          
          try:
               opening = open("myfile.json" , "r")
               json_list = json.load(opening)
               opening.close()
          except FileNotFoundError:
               json_list=[]

          flag=0
          for user in json_list:
               
               if user["Email"] == email :
                    print("* Email checked , Hi " , user["Fname"] , ";) *")
                    flag=1 
                    break
                    
          if not flag:
               print("* Email not found , try again *") 
               continue
     
          while True: 
               password=input("Enter your password: ")              
               for user in json_list:
                    if user["Email"] == email and user["Password"] == password:
                         print("* Logged in successfully. *")  
                         break     
               
               else:
                    print("* Incorrect password , please try again *")
               
               return email

          
    



if __name__ == '__main__':
     
     while True:
          print("1-REGISTER")
          print("2-LOGIN")
          print("3-Exit")
          selection=input("Enter your selection (1)REGISTER , (2)LOGIN , (3)EXIT    : ")
          if selection == '1':
               register()
               time.sleep(2)
               os.system('cls')
          elif selection == '2':
               userMail = login()               
               time.sleep(2)
               os.system('cls')
               Main_Menu.Menu(userMail)
          elif selection == '3':
               os.system('cls')
               print("EXITTING..")
               break
          else:
               print("* INVALID ENTRY! , TRY AGAIN *")
               time.sleep(2)
               os.system('cls')
     
     
     
     

     