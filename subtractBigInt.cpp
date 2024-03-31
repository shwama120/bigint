#include <iostream>
#include <string>

std::string subtractBigInt(std::string num1, std::string num2) {
    std::string zeros = "";
    int res[1000] = {0};
    bool negative = false;

    int len1 = num1.size();
    int len2 = num2.size();
    int size_diff = len1 - len2;

    if (size_diff < 0)
        size_diff *= -1;
    for (int i = 0; i < size_diff; i++)
        zeros += "0";
    if (len1 < len2)
        num1 = zeros + num1;
    else if (len1 > len2)
        num2 = zeros + num2;

    if (num1 < num2) {
        std::swap(num1, num2);
        negative = true;
    }

    int n1, n2;
    int borrow = 0;
    for (int i = len1 - 1; i >= 0; i--) {
        n1 = num1[i] - '0';
        n2 = num2[i] - '0';

        int diff = n1 - n2 - borrow;

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        res[i] = diff;
    }

    std::string result = "";
    bool leading_zero = true;
    for (int i = 0; i < len1; i++) {
        if (res[i] != 0 || !leading_zero) {
            result += std::to_string(res[i]);
            leading_zero = false;
        }
    }

    if (negative)
        result = "-" + result;

    return result;
}
