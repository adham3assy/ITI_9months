class node:
    def __init__(self,id,name,position):
        self.id = id
        self.name = name
        self.position = position
        self.next = None
        self.prev = None

class linkedlist:
    def __init__(self):
        self.head = None
        self.tail = None

    def Add(self,id,name,position):
        new_node = node(id,name,position)
        if self.head == None:
            self.head = new_node
            self.tail = new_node
        else:
            node.prev = self.tail
            self.tail.next = new_node
            self.tail = new_node
    
    def insert(self,id,name,position,loc):
        new_node = node(id,name,position)
        if self.head == None:
            self.head = new_node
            self.tail = new_node
        elif loc==0:
            self.head.prev = new_node 
            new_node.next = self.head
            self.head = new_node
        else :
            i=0
            current = self.head 
            while i<loc-1 and current != None:
                current = current.next
                i += 1
            
            if self.tail == current or current == None:
                new_node.prev =self.tail
                self.tail.next = new_node
                self.tail = new_node

            else : 
                current.next.prev = new_node
                new_node.next = current.next
                current.next = new_node
                new_node.prev = current


    def Delete_by_id(self,id):
        if self.head == None :
            return False
        if self.head == self.tail :
            if self.head.id == id :
                self.head = None
                self.tail = None
                return True
            else :
                return False
        if self.head.id == id:
            self.head = self.head.next
            return True
        if self.tail.id == id:
            self.tail = self.tail.prev
            return True
        curr = self.head 
        while curr != None:
            if curr.id == id :
                curr.next.prev = curr.prev
                curr.prev.next = curr.next
                return True
            curr = curr.next
        return False

    def Display_all(self):
        if self.head == None:
            return False
        curr = self.head
        i = 1
        while curr != None:
            print("Emp",i,"id:",curr.id ,"  <->   Emp",i ,"name:",curr.name ,"  <->   Emp",i ,"position:",curr.position)
            i+=1
            curr = curr.next

    def Delete_all(self):
        if self.head == None:
            return False 
        else:
            self.head = None
            self.tail = None

    def Update(self,id,new_name,new_position):
        if self.head == None:
            return False
        curr = self.head
        while curr!=None:
            if curr.id == id:
                curr.name = new_name
                curr.position = new_position
                return True
            curr = curr.next
        return False
    


    

if __name__ == "__main__":
    ll = linkedlist()
    ll.Add(11,'Omar','developer')
    ll.Add(22,'yahia','Assistant')
    ll.insert(30,'Adham','CEO',0)
    ll.insert(44,'Ahmed','tester',4)
    ll.Update(22,'Shady','UI/UX')
    ll.Display_all()