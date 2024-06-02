#include<stdio.h>
int main(){
    float weight [30] , profit[30] , ratio[30],total_value = 0,temp,capacity;
    int n,i,j;
    printf("Enter the number of items - ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the weight  and profit of item %d \n - ", i+1);
        scanf("%f %f",&weight[i],&profit[i]);
    }
    printf("Enter the capacity of the Bag - ");
    scanf("%f",&capacity);
    for(i=0;i<n;i++){
        ratio[i] = profit[i]/weight[i];
}
for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
        if(ratio[i]<ratio[j]){
            temp = ratio[j];
            ratio[j] = ratio[i];
            ratio[i] = temp;

            temp = weight[j];
            weight[j] = weight[i];
            weight[i] = temp;

            temp = profit[j];
            profit[j] = profit[i];
            profit[i] = temp;

        }
    }

}    

    for ( i = 0; i < n; i++){
        if(weight[i] > capacity){
             break;
    }

    else{
        total_value += profit[i];
        capacity -= weight[i];
    }
 }

  if (i<n){
    total_value += ratio[i]*capacity ;
  }
  
  printf("\n The maximum value is - %f \n",total_value);
   return 0;
}
   







