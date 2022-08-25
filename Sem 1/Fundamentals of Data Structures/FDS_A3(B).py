str=" "
str=input("Enter String: ")
def long_len():
    str_list=[]
    long_len=[]
    str_list=str.split(" ")
    for i in str_list:
        long_len.append(len(i))
    long_len.sort(reverse=True)
    print("Word is= ",str_list[0])
    print(max(long_len))

def freq_char():
    c=input("Enter Character for Finding its Frequency in String")
    print("C=",c)
    g=str.count(c)
    print(g)

def str_pali():
    str=input("Enter Character for Finding its Frequency in String")
    m=str[::-1]
    print(m)
    if str==m:
        print("String is Palindrome")
    else:
        print("String is not Palindrome")

def index_substr():
    print("Enter Character for Finding its Frequency in String")
    str_sub = input()
    list_str = str.split(" ")
    for i in range(len(list_str)):
        if str_sub==list_str[i]:
            print(str)
            print(i)
            break

def freq_word():
    list_str=str.split(" ")
    print("****Count if each word in String*****")
    for i in range(len(list_str)):
        print(list_str[i],list_str.count(list_str[i]))

if __name__ == '__main__':
    print("*****Take Input*****")
    while(True):
        print("1. To Display Word with the Longest Length")
        print("2. To Determine the Frequency of Occurrence of Particular Character in the String")
        print("3. To check whether given String is Palidrome or not")
        print("4. To Display Index of First Appearance of the Substring")
        print("5. To Count the Occurrence of each word in a given String")
        print("6. Exit")
        print("Enter Your Choice")
        ch=int(input())
        if(ch==1):
            long_len()
        if(ch==2):
            freq_char()
        if(ch==3):
            str_pali()
        if(ch==4):
            index_substr()
        if(ch==5):
            freq_word()
        if(ch==6):
            exit()