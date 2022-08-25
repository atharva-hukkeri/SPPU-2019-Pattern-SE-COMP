def entries(a):
    n = int(input("Enter Number of student:"))
    for i in range(n):
        m = float(input("Enter percentage of student:"))
        a.append(m)
    print("Array Entries are Recorded\n\n")


def display(a):
    n = len(a)
    if n == 0:
        print("No records entered\n")
    else:
        print("Array of percentage:  ", end='  ')
        for i in range(len(a)):
            print(a[i], end='  ')
    print("\n")


def Insertion_sort(a):
    n = len(a)
    for i in range(1, n):
        temp = a[i]
        j = i - 1
        while j >= 0 and a[j] > temp:
            a[j + 1] = a[j]
            j -= 1
        a[j + 1] = temp
    print("Array of Percentage is sorted by Insertion sort\n", a)


def Shell_sort(a):
    n = len(a)
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            temp = a[i]
            j = i
            while j >= gap and a[j - gap] > temp:
                a[j] = a[j - gap]
                j -= gap
            a[j] = temp
        gap //= 2
    print("Array of Percentage is Sorted by Shell sort\n\n", a)


a = []
while True:
    print("1. Display array of FE percentage.")
    print("2. sort by Insertion sort")
    print("3. sort by Shell sort and Display top scores")
    print("4. Exit.")
    ch = int(input("Enter your choice: "))
    if ch == 1:
        entries(a)
        display(a)
        print("\n")
    elif ch == 2:
        print("Percentage before Sorting\n")
        display(a)
        print("Percentage after Sorting\n")
        Insertion_sort(a)
        print("\n")

    elif ch == 3:
        print("Percentage Before Sorting\n")
        display(a)
        print("Percentage after Sorting\n")
        Shell_sort(a)
        n = len(a)
        if n >= 5:
            print("------------Top five scores----------\n")
            for i in range(n - 1, n - 6, -1):
                print(a[i], "\n")
        else:
            print("----------Top scores-----------\n")
            for j in range(n - 1, -1, -1):
                print(a[j], "\n")

    elif ch == 4:
        print("Program Finished!!")
        quit()
    else:
        print("Invalid choice,Try again.")
