# ifndef COLOR_H
# define COLOR_H

enum Color {
    red,
    orange,
    green,
    cyan,
    blue,
    magenta
};

bool isPrimary(Color c) {
    return c == Color::red || c == Color::green || c == Color::blue;
}

# endif

