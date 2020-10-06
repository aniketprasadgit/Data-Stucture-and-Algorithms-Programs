class Node:    
    def __init__(self,data):    
        self.data = data;    
        self.previous = None;    
        self.next = None;    
            
class ReverseList:        
    def __init__(self):    
        self.head = None;    
        self.tail = None;    
            
    def addNode(self, data):    
        newNode = Node(data);    
                
        if(self.head == None):  
            self.head = self.tail = newNode;     
            self.head.previous = None;    
            self.tail.next = None;    
        else:    
            self.tail.next = newNode;     
            newNode.previous = self.tail;     
            self.tail = newNode;    
            self.tail.next = None;    
            
    def reverse(self):    
        current = self.head;    
            
        while(current != None):    
            temp = current.next;    
            current.next = current.previous;    
            current.previous = temp;    
            current = current.previous;       
        temp = self.head;    
        self.head = self.tail;    
        self.tail = temp;    
            
    def display(self):       
        current = self.head;    
        if(self.head == None):    
            print("List is empty");    
            return;    
                
        while(current != None):    
            print(current.data),    
            current = current.next;
