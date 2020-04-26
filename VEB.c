#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define INT_MIN -1000000000

struct node{
    int max,min;
    int universe_size;
    struct node* summary;
    struct node** clusters;
};

int high(struct node* helper,int x){
    int div = ceil(sqrt(helper->universe_size));
    return x / div;
}

    // Function to return position of x in cluster
int low(struct node* helper,int x){
        int mod = ceil(sqrt(helper->universe_size));
        return x % mod;
}

int generate_index(struct node* helper,int x, int y){
    int ru = ceil(sqrt(helper->universe_size));
    return x * ru + y;
}

struct node* Van_Emde_Boas(int size){
        struct node *newNode;
        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->max = -1;
        newNode->min = -1;
        newNode->universe_size = size;
        // Base case
        if (size <= 2) {
            newNode->summary = NULL;
            newNode->clusters = NULL;

        }
        else {
            int no_clusters = ceil(sqrt(size));

            // Assigning VEB(sqrt(u)) to summary
            newNode->summary = (struct node*)malloc(sizeof(struct node)*no_clusters);
            newNode->clusters = (struct node**)malloc(sizeof(struct node*)*no_clusters);

            int i;
            for (i = 0; i < no_clusters; i++) {
                newNode->clusters[i] = Van_Emde_Boas(ceil(sqrt(size)));
            }
        }
        return newNode;
}

int VEB_min(struct node* helper){
    return (helper->min == -1 ? -1 : helper->min);
}

int VEB_max(struct node* helper){
    return (helper->max == -1 ? -1 : helper->max);
}

void insert(struct node* helper, int key){
    if (helper->min == -1){
        helper->min = key;
        helper->max = key;
    }
    else{
        if (key < helper->min){

            int temp = helper->min;
            helper->min = key;
            key = temp;
        }

        if (helper->universe_size > 2){

            if (VEB_min(helper->clusters[high(helper,key)]) == -1){
                insert(helper->summary, high(helper,key));

                helper->clusters[high(helper,key)]->min = low(helper,key);
                helper->clusters[high(helper,key)]->max = low(helper,key);
            }
            else{
                insert(helper->clusters[high(helper,key)], low(helper,key));
            }
        }
         if (key > helper->max){
            helper->max = key;
        }
    }
}

int VEB_successor(struct node* helper, int key){

    if (helper->universe_size == 2){

        if (key == 0 && helper->max == 1){
            return 1;
        }
        else {
            return -1;
        }
    }

    else if (helper->min != -1 && key < helper->min){

        return helper->min;
    }
    else{

        int cls_max = VEB_max(helper->clusters[high(helper,key)]);

        int offset, succ_cluster;

        if (cls_max!= -1&&low(helper,key) < cls_max){

            offset = VEB_successor(helper->clusters[high(helper,key)],
                                   low(helper,key));

            return generate_index(helper,high(helper,key), offset);
        }

        else{

            succ_cluster = VEB_successor(helper->summary, high(helper,key));

            if (succ_cluster == -1){
                return -1;
            }
            else{

                offset = VEB_min(helper->clusters[succ_cluster]);

                return generate_index(helper,succ_cluster, offset);
            }
        }
    }
}

int main(){
    int n,size;
    printf("Enter the size of Universe: ");
    scanf("%d",&size);
    struct node* helper = Van_Emde_Boas(size);
    printf("Enter the number of terms in array: ");
    scanf("%d",&n);
    printf("Enter the elements in array: \n");
    int a[n],i,maxi=INT_MIN;
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        insert(helper,a[i]);
    }
    int x;
    printf("Enter the number whose sucessor you need to find: ");
    scanf("%d",&x);
    printf("Successor of %d is %d\n",x,VEB_successor(helper,x));


}