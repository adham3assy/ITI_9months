class node:
    def __init__(self,id,name,position):
        self.id = id
        self.name = name
        self.position = position
        self.next = None
        

class Queue:
    def __init__(self,s):
        self.head = None
        self.tail = None
        self.size = s
        self.i = 0

    def Enqueue(self,id,name,position):
        new_node = node(id,name,position)
        if self.i < self.size :
            if self.head == None :
                self.head = new_node
                self.tail = new_node
                self.i+=1

            else:
                self.tail.next = new_node
                self.tail = new_node
                self.i+=1
        else:
            print("The Queue is full!")


    def Dequeue(self):
        if self.head == None :
            print("The Queue is empty!")
        else:
            curr = self.head
            self.head = curr.next
            self.i -=1
            return curr

if __name__ == "__main__":
    qq = Queue(5)
    qq.Enqueue(11,'Omar','developer')        
    qq.Enqueue(11,'Omar','developer')        
    qq.Enqueue(11,'Omar','developer')        
    qq.Enqueue(11,'Omar','developer')        
    qq.Enqueue(11,'Omar','developer')        
    qq.Enqueue(11,'Omar','developer')   
    qq.Dequeue()     
    qq.Dequeue()     
    qq.Dequeue()     
    qq.Dequeue()     
    qq.Dequeue()     
    qq.Dequeue()     
        
