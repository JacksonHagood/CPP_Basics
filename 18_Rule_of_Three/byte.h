# ifndef BYTE_H
# define BYTE_H

class Byte {
    private:
        unsigned char* value;

    public:
        // constructors
        Byte() : value(0) {}
        Byte(unsigned char VALUE) : value(new unsigned char{VALUE}) {}

        // getter and setter
        int getByte() { return *value; }
        void setByte(unsigned char VALUE) { *value = VALUE; }

        // rule of three

        // copy constructor (ensures deep copy)
        Byte(const Byte& original) : value() {
            // step 1: allocate memory
            this->value = new unsigned char;

            // step 2: copy values
            *(this->value) = *original.value;
        }

        // copy assignment operator
        Byte& operator=(const Byte& original) {
            // step 1: self assignment check
            if (this != &original) {
                // step 2: deallocate memory
                delete this->value;

                // step 3: allocate memory
                this->value = new unsigned char;

                // step 4: copy values
                *(this->value) = *original.value;
            }

            // step 5: return self
            return *this;
        }

        // destructor
        ~Byte() {
            // step 1: deallocate memory
            delete this->value;

            // step 2: handle dangling pointers
            this->value = nullptr;
        }
};

# endif