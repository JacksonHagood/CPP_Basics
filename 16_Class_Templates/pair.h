# ifndef PAIR_H
# define PAIR_H

template <typename T, typename U>
class Pair {
    private:
        T left;
        U right;
    
    public:
        // constructor
        Pair(T LEFT, U RIGHT) : left(LEFT), right(RIGHT) {}

        // getter / setter functions
        T getLeft() const { return left; }
        U getRight() const { return right; }

        void setLeft(const T LEFT) { left = LEFT; }
        void setRight(const U RIGHT) { right = RIGHT; }
};

# endif