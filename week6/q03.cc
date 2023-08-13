class Solution {
public:
    int myAtoi(string s) {
        stringstream ss(s);

        // ignore whitespace
        char c;
        while ((c = ss.peek()) != -1) {
            if (c != ' ') break;
            ss.get();
        }

        // check sign
        int sign = 1;
        c = ss.peek();
        if (c == -1) return 0;

        if (c == '-') {
            sign = -1;
            ss.get();
        } else if (c == '+') {
            sign = 1;
            ss.get();
        }
        // maybe should do error check to make sure next character is a digit?

        // read rest of characters
        uint64_t total = 0;
        while ((c = ss.get()) != -1) {
            if (!isdigit(c)) break;

            int digit = c - '0';
            total = total * 10 + digit;

            if (total > 2147483647 && sign == 1) total = 2147483647;
            if (total > 2147483648 && sign == -1) total = 2147483648;
        }

        return sign * total;
        
    }
};
