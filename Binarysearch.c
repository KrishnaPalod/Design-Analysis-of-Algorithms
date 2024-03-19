#include<stdio.h>
int search(float a[],int low,int high,float target){
    while(low<=high){
        int mid=low+(high-low)/2;
          if (target==a[mid]){
            return mid;
        }
        if(target>a[mid]){
            low=mid+1;
        }
        if(target<a[mid]){
            high=mid-1;
        }
    }
    return -1;
}
void main(){
    int n,k;
    char ch;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    float a[n],target;
    int mid; 
    printf("Enter numberes : ");
    for (k=0;k<n;k++){
        scanf("%f",&a[k]);
    }
    printf("\nEntered numberes are : ");
    for (k=0;k<n;k++){
        printf("%g ",a[k]);
    }
do{
    printf("\nEnter the number to search : ");
    scanf("%f",&target);
    int result = search(a, 0, n-1, target);
    if (result == -1){
        printf("Target not found");
        printf("\nDo you want to search another number y/n : ");
        scanf(" %c",&ch);
        if(ch == 'n' || ch == 'N'){
            printf("OK, Thanks for using our code");
            break;
            }
        }
    else{
        printf("\ntarget %g is found at index %d",target,result);
    }
    }while(ch == 'Y'|| ch == 'y');

}