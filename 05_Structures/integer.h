# ifndef INTEGER_H
# define INTEGER_H

union Integer {
    int8_t charValue;
    int16_t shortValue;
    int32_t intValue;
    int64_t longValue; // union will be 8 bytes
};

# endif
