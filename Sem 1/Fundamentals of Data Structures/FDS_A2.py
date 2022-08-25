marks=[]
def stud_get():
    print("Enter Number oF Students In SE Class: ")
    N = int(input())
    global marks
    for i in range(N):
        print("Enter the Marks(Write -1 for Absent Students)")
        M = int(input())
        marks.append(M)
    print(marks)

def avg_marks():
    sum=0
    cnt=0
    for i in range(len(marks)):
        if marks[i] != -1:
            sum=sum+marks[i]
            cnt+=1
    print("Total Marks= ",sum)
    print("Average in Float= ", sum/cnt)
    print("Average in Integer= ", sum//cnt)

def high_low():
    temp=marks[0]
    for i in range(len(marks)):
        if temp < marks[i]:
            temp=marks[i]
    print("Highest Marks= ",temp)
    temp=marks[0]
    for i in range(len(marks)):
        if marks[i] != -1:
            if temp>marks[i]:
                temp=marks[i]
    print("Lowest Marks= ",temp)

def count_abs():
    cnt=0
    for i in range(len(marks)):
        if marks[i] == -1:
            cnt+=1
    print("Number of Students Absent: ",cnt)

def high_freq():
    freq=[]
    for i in range(len(marks)):
        if marks[i] != -1:
            freq.append(marks.count(marks[i]))
    print(freq)
    k=max(freq)
    print("Highest Frequency+ ",k)
    print("Highest Marks= ",marks[k])

if __name__ == '__main__':
    print("*****TAKE INPUT*****")
    stud_get()
    while(True):
        print("1. The Average Score of Class: ")
        print("2. Highest Score and Lowest Score of Class: ")
        print("3. Count of Students who were Absent for the Test: ")
        print("4. Display Marks with Highest frequency: ")
        print("5. EXIT")
        print("Enter Choice")
        choice=int(input())
        if(choice==1):
            avg_marks()
        if(choice==2):
            high_low()
        if (choice == 3):
            count_abs()
        if (choice == 4):
            high_freq()
        if (choice == 5):
            exit()