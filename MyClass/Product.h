
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

    Product& operator = (const Product& prod) {
        id = prod.id;
        price = prod.price;
        return *this;
    }
    friend bool operator < (const Product& prod1, const Product& prod2);
    friend bool operator > (const Product& prod1, const Product& prod2);
    friend bool operator != (const Product& prod1, const Product& prod2);
    friend bool operator == (const Product& prod1, const Product& prod2);
};

bool operator < (const Product& prod1, const Product& prod2) {
    if( prod1.id < prod2.id )
        return true;
    else
        return false;
}

bool operator > (const Product& prod1, const Product& prod2) {
    if( prod1.id > prod2.id )
        return true;
    else
        return false;
}

bool operator != (const Product& prod1, const Product& prod2) {
    if( (prod1.id == prod2.id) && (prod1.price == prod2.price) )
        return false;
    else
        return true;
}

bool operator == (const Product& prod1, const Product& prod2) {
    if( (prod1.id == prod2.id) && (prod1.price == prod2.price) )
        return true;
    else
        return false;
}

namespace std {
    template<>
    struct hash<Product> {
        std::size_t operator() (const Product& prod) const {
            return hash<int>()(prod.id);
        }
    };
}

#endif //BENCHMARKS_PRODUCT_H
