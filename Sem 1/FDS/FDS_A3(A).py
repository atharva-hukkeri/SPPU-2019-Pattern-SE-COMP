class test:
    arr = []
    n = 0
    def __init__(self):
        for i in range(10):
            self.arr.append([])
            for j in range(10):
                self.arr[i].append(0)
        self.n = int(input("Enter Value of n: "))

    def accept(self):
        print("Enter the Elements: ")
        for i in range(0,self.n):
            print("Enter Row ",i+1,": ")
            for j in range(0,self.n):
                self.arr[i][j] = int(input())

    def therow(self):
        sum = []
        for i in range(0,self.n):
            sum.append(0)
        for i in range(0,self.n):
            for j in range(0,self.n):
                sum[i] = sum[i] + self.arr[i][j]

        for i in range(0,self.n):
            if(sum[0]!=sum[i]):
               return 0;
        return 1;

    def thecolumn(self):
        sum = []
        for i in range(self.n):
            sum.append(0)
        for i in range(0,self.n):
            for j in range(0,self.n):
                sum[i] = sum[i]+self.arr[j][i]
        for i in range(0,self.n):
            if(sum[0]!=sum[i]):
                return 0
        return 1

    def diagonal(self):
        d1=d2=0
        for i in range(0,self.n):
            for j in range(0,self.n):
                if(i==j):
                    d1 = d1+self.arr[i][j]
                if(i+j==self.n-1):
                    d2=d2+self.arr[i][j]
        if(d1!=d2):
            return 0
        return 1

m = test()
m.accept()
if(m.diagonal()==1 and m.therow()==1 and m.thecolumn()==1):
    print("It is a Magic Matrix")
else:
    print("Sorry. It is not a Magic Matrix")