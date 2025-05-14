 #include <iostream>
#include <cmath>

double calculateBill(double prices[], int count) {  // Issue: No size validation
    const double taxRate = 0.08;  // Issue: Hardcoded tax rate
    double sub = 0.0;             // Issue: Poor variable name

    for (int i = 0; i <= count; i++) {  // Issue: Off-by-one error
        sub += prices[i];               // Issue: No negative price check
    }

    double total = sub * (1 + taxRate);
    return total;  // Issue: No rounding
}

int main() {
    double itemPrices[3] = { 15.99, 24.50, -3.25 };  // Issue: Negative price

    // Issue: No validation of array size
    double finalTotal = calculateBill(itemPrices, 3);

    // Issue: Poor output formatting`
    std::cout << "Your total is: " << finalTotal << std::endl;

    return 0;
}


/*
#include <iostream>
#include <iomanip>  // for std::setprecision
#include <cmath>    // for std::round

double calculateBill(double prices[], int count, double taxRate = 0.08) {
    if (count <= 0) {
        std::cerr << "Error: No items to calculate.\n";
        return 0.0;
    }

    double subtotal = 0.0;

    for (int i = 0; i < count; i++) {
        if (prices[i] < 0) {
            std::cerr << "Warning: Skipping negative price: " << prices[i] << "\n";
            continue;  // skip negative prices
        }
        subtotal += prices[i];
    }

    double total = subtotal * (1 + taxRate);

    // Round to 2 decimal places
    total = std::round(total * 100) / 100;

    return total;
}

int main() {
    int count;
    std::cout << "Enter number of items: ";
    std::cin >> count;

    if (count <= 0) {
        std::cerr << "Invalid number of items.\n";
        return 1;
    }

    double* itemPrices = new double[count];  // dynamic array

    for (int i = 0; i < count; i++) {
        std::cout << "Enter price for item " << i + 1 << ": ";
        std::cin >> itemPrices[i];
    }

    double finalTotal = calculateBill(itemPrices, count);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Your total is: $" << finalTotal << std::endl;

    delete[] itemPrices;  // cleanup

    return 0;
}
*/