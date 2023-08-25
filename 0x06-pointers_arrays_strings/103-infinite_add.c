#include <stdio.h>
#include <string.h>

char *infinite_add(char *n1, char *n2, char *r, int size_r) {
    int carry = 0;  // Initialize carry to 0
    int index1 = strlen(n1) - 1; // Get the last index of n1
    int index2 = strlen(n2) - 1; // Get the last index of n2
    int result_index = 0; // Initialize the result index to 0

    // While there are digits left in either n1 or n2 or there's a carry
    while (index1 >= 0 || index2 >= 0 || carry) {
        int digit1 = (index1 >= 0) ? n1[index1] - '0' : 0; // Convert char to int
        int digit2 = (index2 >= 0) ? n2[index2] - '0' : 0; // Convert char to int

        int sum = digit1 + digit2 + carry;
        carry = sum / 10; // Calculate carry for the next iteration
        int digit_sum = sum % 10; // Calculate the current digit of the result

        // Check if there's enough space in the result buffer
        if (result_index < size_r - 1) {
            r[result_index++] = digit_sum + '0'; // Convert int to char and store in result buffer
        } else {
            return 0; // If the result cannot be stored in r, return 0
        }

        // Move to the next digit in n1 and n2 (if available)
        index1--;
        index2--;
    }

    r[result_index] = '\0'; // Null-terminate the result string
    // Reverse the result string in-place
    int i = 0, j = result_index - 1;
    while (i < j) {
        char temp = r[i];
        r[i] = r[j];
        r[j] = temp;
        i++;
        j--;
    }

    return r; // Return a pointer to the result
}

int main() {
    char n1[] = "12345";
    char n2[] = "6789";
    char result[20]; // Assuming a buffer size of 20

    char *sum = infinite_add(n1, n2, result, sizeof(result));

    if (sum) {
    printf("Sum: %s\n", sum);
} else {
printf("Result cannot be stored in the buffer.\n");
}

return 0;
}

