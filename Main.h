// ---------------- Edit these constraints as per requirement-------------------//

const int NUM=3;
const int MAX[NUM] = {5,2,3};
const int MAX_ITERATIONS = 100;

// ---------------------------------------------------------------------------//

template <typename T> class buks{
    public:
    T arr[NUM];
    int depth;
    buks() = default;
    buks(int* arra);


    bool operator!=(buks<T> t);

    buks neighbour(int i, int j);

};