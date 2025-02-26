import json
from datetime import datetime
import time
import os


 
class Project:
     def __init__(self , Title , Details , Target , Start_date , End_date , Owner):
          self.Title = Title
          self.Details = Details  
          self.Target = Target
          self.Start_date =str(Start_date)
          self.End_date = str(End_date)
          self.Owner = Owner
          

def load_projects():
    try:
        with open("projects.json", "r") as opening:
            return json.load(opening)
    except FileNotFoundError:
        return []


def save_projects(project_list):
    with open("projects.json", "w") as json_file:
        data = json.dumps(project_list, indent=4)
        json_file.write(data)


def Menu(userMail):
     print("------- Main Menu ------- (LOGGED IN AS : " , userMail , " -------)")
     print("1-Create New Project")
     print("2-View All Projects")  
     print("3-Edit Project")
     print("4-Delete Project")
     print("5-Search")
     print("6-LOG OUT")
     choice = input("Choose From The Menu (1)(2)(3)(4)(5)(6) : ")
     if choice == '1' :
        os.system('cls')
        Create_project(userMail)
        time.sleep(2)
        os.system('cls')
        Menu(userMail)
     elif choice == '2' :
        os.system('cls')
        View_all()
        time.sleep(5)
        os.system('cls')
        Menu(userMail)
     elif choice == '3' :
        os.system('cls')
        Edit_project(userMail)
        time.sleep(2)
        os.system('cls')
        Menu(userMail)
     elif choice == '4' :
        os.system('cls')
        Delete_project(userMail)
        time.sleep(2)
        os.system('cls')
        Menu(userMail)
     elif choice == '5' :
        os.system('cls')
        Search_for_project()
        time.sleep(2)
        os.system('cls')
        Menu(userMail)
     elif choice == '6' :
        os.system('cls')
        print("* Logged out! *")
        userMail = None
        time.sleep(2)
        os.system('cls')
        return
     


def Create_project(userMail):
    project_list = load_projects()
    print("------- Create New Project ------- (LOGGED IN AS : " , userMail , " -------)")
    Title = input("Enter your campaign title : ").upper()
    Details = input("Enter your campaign details : ").capitalize()
    while True: 
            flag=0
            Target = input("Enter your campaign Target : ")
            if Target.isdigit() == True :
                flag=1
            if not flag:
                print("* INVALID TARGET MUST BE NUMERIC , TRY AGAIN *")
                time.sleep(2)
                os.system('cls') 
                print("------- Create New Project -------")
                print("Title:" , Title)
                print("Details:" , Details)
                continue           
            
            Start_date =input("Set your project Start Date(yyyy-mm-dd) : ")
            try:
                Start_date = datetime.strptime(Start_date , "%Y-%m-%d").date()
            except ValueError:
                print("* INVALID DATE , TRY AGAIN *")
                time.sleep(2)
                os.system('cls') 
                print("------- Create New Project -------")
                print("Title:" , Title)
                print("Details:" , Details)
                print("Target:" , Target)
                
            End_date = input("Set your project End Date(yyyy-mm-dd) : ")
            try:
                End_date = datetime.strptime(End_date , "%Y-%m-%d").date()            
            except ValueError:
                print("* INVALID DATE , TRY AGAIN *")
                time.sleep(2)
                os.system('cls') 
                print("------- Create New Project -------")
                print("Title:" , Title)
                print("Details:" , Details)
                print("Target:" , Target)
                print("Start Date:" , Start_date)
                continue

            new_project = Project(Title , Details , Target , Start_date , End_date ,userMail)
            project_list.append(new_project.__dict__)
            save_projects(project_list)
            
            print("* Project Created Successfully *")
            time.sleep(2)
            break

def View_all():
    print("------- All Projects -------")

    project_list = load_projects()
    
    if not project_list :
         print("* No Projects Found! *")
    else:
         for project in project_list:
            print("Title:" , project['Title'] , " , Details:" , project['Details'] , " , Target:" , project['Target'] , " , Start Date:" , project['Start_date'] , " , End Date:" , project['End_date'] , " , Owner:" , project['Owner'])
    time.sleep(5)


def Edit_project(userMail):
    
    project_list = load_projects()
    while True:
        print("------- Edit Project ------- (LOGGED IN AS : " , userMail , " -------)")
        title = input("Enter the project's title to edit : " ).upper()        
        projectfound=0 
        accessfound=0
        for project in project_list:
            if project['Title'] == title :
                projectfound=1
                if userMail == project['Owner'] :
                    accessfound=1
                    project['Details'] = input("Enter new details : ")
                    project['Target'] = input("Enter new Target : ")
                    project['Start_date'] = input("Set new start date : ")
                    project['End_date'] = input("Set new end date : ")

                    save_projects(project_list)

                    print("* Project Updated Successfully! *")
                    time.sleep(1)
                    return
                else:
                    print("* You don't have access to edit in this project *")
                    time.sleep(1)
                    os.system('cls')
                    break 
            
               
        if not projectfound :
            print("* No Project Found With This Title! *")
            time.sleep(1)
            os.system('cls')
        
        if not projectfound or not accessfound:
            continue
        


def Delete_project(userMail):
    project_list = load_projects()
    while True:
        print("------- Delete Project ------- (LOGGED IN AS : " , userMail , " -------)")
        title = input("Enter the project's title to delete : " ).upper()
        projectfound=0
        accessfound=0    
        for project in project_list:
            if project['Title'] == title :
                projectfound=1
                if userMail == project['Owner']:
                    accessfound=1  
                    project_list.remove(project)
                    save_projects(project_list)
                    print("* Project Deleted Successfully! *")
                    time.sleep(1)
                    os.system('cls')
                    
                else:
                    print("* You don't have the access to delete this project! *")
                    time.sleep(1)
                    os.system('cls')
                    
            
        if not projectfound:
            print("* No Project Found With This Title! *")
            time.sleep(1)
            os.system('cls')

        if not projectfound or not accessfound:
            continue

        break
        

def Search_for_project():
    
    project_list = load_projects()
    while True:
        print("------- SEARCH By Start Date -------")
        start_date = input("Enter the project's start date(dd-mm-yyyy) : " )
        try:
            start_date = datetime.strptime(start_date , "%d-%m-%Y").date()
        except ValueError:
            print("* INVALID DATE , TRY AGAIN *")
            time.sleep(1)
            os.system('cls')
            #print("------- SEARCH By Start Date -------")
            continue
        flag=0
        for project in project_list :
            if project['Start_date'] == str(start_date) : 
                print("Title:" , project['Title'] , " , Details:" , project['Details'] , " , Target:" , project['Target'] , " , Start Date:" , project['Start_date'] , " , End Date:" , project['End_date'] , ", Owner:" , project['Owner'])
                flag=1
                time.sleep(2)
                os.system('cls')
                break
                
        if flag:
            break
        else:
            print("* No project found with this Start date! *")
            time.sleep(1)
            os.system('cls')
            break