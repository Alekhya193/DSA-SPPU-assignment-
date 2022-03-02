#include<iostream>

using namespace std;
int const N=5;
int arr[N];
int front=-1;
int rear=-1;

bool isempty(){
        if (front==-1 && rear==-1)
        {
           return true;
        }
        else{
            return false;
        }
        
    }

bool isfull(){
    if (((rear+1)%N)==front)
    {
        return true;
    }
    else{
        return false;
    }
    
}

void enqueue(int value){
    if (isempty())
    {
         rear=front=0;
            arr[rear]=value;
            cout<<"ENQUEUED"<<value<<endl;


    }
    else if (isfull())
    {
        cout<<"overflow condition"<<endl;
    }
    else{
        rear=(rear+1)%N;
        arr[rear]=value;
        cout<<"ENQUEUED"<<value<<endl;
    }
    
    
}

void dequeue(){
    if (isempty())
    {
       cout<<"underflow condition"<<endl;
    }
    else if (front==rear)
    {
        cout<<arr[front]<<"DEQUEUED"<<endl;
        front=rear=-1;
    }
    else{
        cout<<arr[front]<<"DEQUEUED"<<endl;
        front=(front+1)%N;
    }
    
    
}

void display(){
    int i=front;
    if (isempty())
    {
        cout<<"underflow condition"<<endl;
    }
    else{
        cout<<"Queue is [";
        while (i!=rear)
        {
            cout<<arr[i]<<" ";
            i=(i+1)%N;
        }
        cout<<arr[i]<<"]";
    }
    
}

int main(int argc, char const *argv[])
{
    
    

    int option,value;

    do
    {
        cout<<"select any one option and 0 to exit"<<endl;
        cout<<"1. enqueue()"<<endl;
        cout<<"2. denqueue()"<<endl;
        cout<<"3. display()"<<endl;
       cout<<"enter";

        cin>>option;

        switch (option)
        {
        case 0:
            
            break;

        case 1:
        cout<<"enter the value that you want to enqueue"<<endl;
        cin>>value;
        enqueue(value);
        break;

        case 2:
        dequeue();
        break;

        case 3:
        display();
        break;
        
        default:
        cout<<"enter proper option"<<endl;
            break;
        }
    } while (option!=0);
    

    return 0;
}
