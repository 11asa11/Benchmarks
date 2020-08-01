
#ifndef BENCHMARKS_PRODUCT_H
#define BENCHMARKS_PRODUCT_H

struct Product {
    int id;
    double price;
    Product() {
        id = 0;
        price = 0.0;
    }
    Product(int id, double price) : id(id), price(price) {}
    Product(const Product& prod) {
        id = prod.id;
        price = prod.price;
    }

    friend bool operator == (const Product& prod1, const Product& prod2);
};

bool operator == (const Product& prod1, const Product& prod2) {
    if( (prod1.id == prod2.id) && (prod1.price == prod2.price) )
        return true;
    else
        return false;
}
#endif //BENCHMARKS_PRODUCT_H
