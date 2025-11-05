#include <stdio.h>
struct Array {
    int data[50];
    int size;
};
int main() {
    struct Array arr;
    int ch,pos,val,i;
    arr.size=0;
    do{
        printf("\n1.Insert 2.Delete 3.Display 4.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter position and value: ");
                scanf("%d%d",&pos,&val);
                for(i=arr.size;i>=pos;i--)
                    arr.data[i]=arr.data[i-1];
                arr.data[pos-1]=val;
                arr.size++;
                break;
            case 2:
                printf("Enter position: ");
                scanf("%d",&pos);
                for(i=pos-1;i<arr.size;i++)
                    arr.data[i]=arr.data[i+1];
                arr.size--;
                break;
            case 3:
                for(i=0;i<arr.size;i++)
                    printf("%d ",arr.data[i]);
                printf("\n");
                break;
        }
    }while(ch!=4);
    return 0;
}

