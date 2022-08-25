import numpy as np
arr1=0
arr2=0
def get_mat():
    global arr1,arr2
    arr1=np.array([[1,2],[5,6]])
    arr2=np.array([[1,2],[5,6]])
    print(arr1)
    print(arr2)

def add():
    arr3=arr1+arr2
    print(arr3)
def sub():
    arr3=arr1-arr2
    print(arr3)
def multi():
    a1 = np.matrix(arr1)
    a2 = np.matrix(arr2)
    arr3 = a1*a2
    print(arr3)
def tran():
    a1=np.transpose(arr1)
    print(a1)
    a2=np.transpose(arr2)
    print(a2)

if __name__ == '__main__':
    print("*****TAKE INPUT*****")
    get_mat()
    while(True):
        print("1. ADDITION of TWO Matrices ")
        print("2. SUBTRACTION of TWO MATRICES ")
        print("3. MULTIPLICATION of TWO MATRICES ")
        print("4. TRANSPOSE of MATRIX ")
        print("5. EXIT")
        print("Enter Your Choice: ")
        ch=int(input())
        if(ch==1):
            add()
        if(ch==2):
            sub()
        if(ch==3):
            multi()
        if(ch==4):
            tran()
        if(ch==5):
            exit()
