# Group A = group of students who play cricket
# Group B = group of students who play badminton
# Group C = group of students who play football

groupA = []
groupB = []
groupC = []
uni = []

def get():
    print("Enter Number of Students who Play Cricket: ")
    C = int(input())
    global groupA
    print("Enter the Roll Number who play Cricket: ")
    for i in range(C):
        cri=int(input("Enter Roll Number: "))
        groupA.append(cri)
    print(groupA)
    global groupB
    print("Enter the Roll Number who play Badminton: ")
    B = int(input())
    for i in range(B):
        bad = int(input("Enter Roll Number: "))
        groupB.append(bad)
    print(groupB)
    global groupC
    print("Enter the Roll Number who play Football: ")
    F = int(input())
    for i in range(F):
        foot = int(input("Enter Roll Number: "))
        groupA.append(foot)
    print(groupC)
    print("Enter Number of Students in Class: ")
    U = int(input())
    global uni
    for i in range(U):
        uni.append(i)
    print(uni)

# List of students who play both cricket and badminton
def cri_bad():
    uni_cri_bad=[]
    for i in groupA:
        for j in groupB:
            if i==j:
                uni_cri_bad.append(j)
    print(uni_cri_bad)

# list of students who play either cricket or badminton but not both
def cri_bad_not_both():
    not_cri_bad = []
    for i in groupA:
        if i not in groupB:
            not_cri_bad.append(i)
    for j in groupB:
        if j not in groupA:
            not_cri_bad.append(j)
    print(not_cri_bad)

# list of students who play neither cricket nor badminton
def nei_cri_nor_bad():
    uni_cri_bad = []
    uni_cri_bad.extend(groupA)
    for j in groupB:
        if j not in groupA:
            uni_cri_bad.append(j)
    print(uni_cri_bad)
    # comparing this to uni array
    not_cri_bad = []
    for i in uni:
        if i not in uni_cri_bad:
            not_cri_bad.append(i)
    print(not_cri_bad)

# list of students who play cricket football and not badminton
def cri_foot_not_bad():
    cri_foot = []
    cri_foot.extend(groupA)
    for i in groupC:
        if i not in groupA:
            cri_foot.append(i)
    final=[]
    for j in cri_foot:
        if j not in groupB:
            final.append(j)
    print(final)
if __name__ == '__main__':
    print("***** Take Input *****")
    get()
    while(True):
        print("1. List of Students who play both Cricket And Badminton: ")
        print("2. List of Students who play either Cricket Or Badminton but Not Both: ")
        print("3. List of Students who play neither Cricket nor Badminton but Not Both: ")
        print("4. List of students who play Cricket And Badminton but not Badminton: ")
        print("5. Exit")
        print("Enter Choice ")
        choice=int(input())
        if(choice==1):
            cri_bad()
        if(choice==2):
            cri_bad_not_both()
        if(choice==3):
            nei_cri_nor_bad()
        if(choice==4):
            cri_foot_not_bad()
        if(choice==5):
            exit()



