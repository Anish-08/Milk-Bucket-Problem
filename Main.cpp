#include<iostream>
#include<queue>

using namespace std;

// ---------------- Edit these constraints as per requirement-------------------//

const int NUM=3;
const int MAX[NUM] = {5,2,3};
const int MAX_ITERATIONS = 100;

// ---------------------------------------------------------------------------//



//Class of buckets 
class buks{
    public:
    int arr[NUM];
    int depth;
    buks() = default;
    buks(int* arra){
        for(int i=0;i<NUM;i++){
            arr[i] = arra[i];
        }
        depth = 0;
    }


    bool operator!=(buks t){
        for(int i=0;i<NUM;i++){
            if(arr[i]!=t.arr[i]) return true;
        }
        return false;
    }

    buks neighbour(int i, int j){
        
        if(arr[j]==MAX[j]){
            buks ans;
            ans = *this;
            return ans;
        }
        else if(arr[j]+arr[i]<=MAX[j]){
            buks ans = *this;
            ans.arr[i]=0;
            ans.arr[j]=arr[j]+arr[i];
            return ans;
        }
        else{
            buks ans = *this;
            ans.arr[i] = arr[i] - MAX[j] + arr[j];
            ans.arr[j] = MAX[j];
            return ans;

        }
    }


};

//Operator to print current state
ostream& operator<<(ostream& os, const buks& b)
{
    os <<b.depth<<": ("<<b.arr[0]<<", "<<b.arr[1]<<", "<<b.arr[2]<<") "<<endl;
    return os;
}

int main()
{
    int max_size=0;
    for(int z=0; z<NUM;z++){
        max_size = max(max_size,MAX[z]);
    }
    max_size++;



    int checker[max_size];
    for(int s=0;s<max_size;s++){
        checker[s] = MAX_ITERATIONS+1;
    }

    cout<<"There are "<<NUM<<" buckets, enter the level of milk in each: "<<endl;

    //We get the starting condition
    int x[NUM] ;
    for(int y=0;y<NUM;y++){
        cout<<"Bucket "<<y+1<<" has MAX size "<<MAX[y]<<" and milk level : ";
        cin>>x[y];
        if(x[y]>MAX[y]) {
            throw std::invalid_argument("Level exceeds maximum capacity");
        }
        if(x[y]<0){
            throw std::invalid_argument("Value cannot be negative");
        }

    }
    buks a(x);

    queue<buks> list;
    list.push(a);
    int iter = MAX_ITERATIONS;
    while(iter--){
        buks y,z;
        y = list.front();
        for(int m=0; m<NUM;m++){
            checker[y.arr[m]]= min(checker[y.arr[m]],y.depth);
        }
        //Uncomment if you want to print at every iteration
        //cout<<y; 

        list.pop();
        
        for(int i=0;i<2;i++){
            for(int j=i+1;j<3;j++){
                z = y.neighbour(i,j);
                z.depth = y.depth+1;
                if(y!=z) list.push(z);
                



                z = y.neighbour(j,i);
                z.depth = y.depth+1;
                if(y!=z) list.push(z);
            }
        }
    

    }
    for(int e=0; e<max_size;e++){
        if(checker[e]<MAX_ITERATIONS+1){
            cout<<e<<": "<<checker[e]<<endl;
        }
        else {
            cout<<e<<": Not Possible"<<endl;
        }
    }

    return 0;
}
