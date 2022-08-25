#include<iostream>
using namespace std;
#define SIZE 10
class DeQueue {
   int Arr[20],Front,Rear;
   public:
      DeQueue();
      void AddAtBegin(int);
      void AddAtEnd(int);
      void DelFront();
      void DelRear();
      void Display();
};
DeQueue::DeQueue() {
   Front=-1;
   Rear=-1;
}
void DeQueue::AddAtEnd(int i) {
   if(Rear>=SIZE-1) {
      cout<<"\n OverFlow occured";
   } else {
      if(Front==-1) {
         Front++;
         Rear++;
      } else {
         Rear=Rear+1;
      }
      Arr[Rear]=i;
      cout<<"\nInserted Element Is: "<<Arr[Rear];
   }
}
void DeQueue::AddAtBegin(int i) {
   if(Front==-1) {
      Front=0;
      Arr[++Rear]=i;
      cout<<"\n Inserted Element Is: "<<i;
   } else if(Front!=0) {
      Arr[--Front]=i;
      cout<<"\n Inserted Element Is: "<<i;
   } else {
      cout<<"\n OverFlow occured";
   }
}
void DeQueue::DelFront() {
   if(Front==-1) {
      cout<<"Dequeue Is Empty";
      return;
   }
   else {
      cout<<"Deleted Element: "<<Arr[Front];
      if(Front==Rear) {
         Front=Rear=-1;
         return;
      } else
         Front=Front+1;
      }
   }
   void DeQueue::DelRear() {
      if(Front==-1) {
         cout<<"Dequeue Is Empty";
         return;
      }
      else {
         cout<<"Deleted Element: "<<Arr[Rear];
         if(Front==Rear) {
            Front=Rear=-1;
         } else
            Rear=Rear-1;
      }
   }
   void DeQueue::Display() {
      if(Front==-1) {
         cout<<"Dequeue is empty";
      } else {
         for(int i=Front;i<=Rear;i++) {
            cout<<Arr[i]<<" ";
         }
      }
   }
   int main() {
      int ch,i;
      DeQueue De1;
      do
 {
  cout<<"\n 1.Add At Beginning";
        cout<<"\n 2.Add At End";
        cout<<"\n 3.Display";
        cout<<"\n 4.Delete From Front";
        cout<<"\n 5.Delete From Rare";
        cout<<"\n 6.Exit";
        cout<<"\n Enter Your Choice: ";
        cin>>ch;
      switch(ch)
 {
         case 1:
            cout<<"Enter The Element To Be Added: ";
            cin>>i;
            De1.AddAtBegin(i);
         break;
         case 2:
            cout<<"Enter The Element To Be Added: ";
            cin>>i;
            De1.AddAtEnd(i);
         break;
         case 3:
            De1.Display();
         break;
         case 4:
            De1.DelFront();
         break;
         case 5:
            De1.DelRear();
         break;
         case 6:

            exit(1);
         break;
         default:
            cout<<"Invalid Choice";
         break;
      }
 }while(ch!=7);
}
