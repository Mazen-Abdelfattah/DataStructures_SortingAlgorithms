//
// Created by youssef on 5/16/2024.
//

#ifndef _ITEM_CLASS_H
#define _ITEM_CLASS_H

#include <iostream>
#include <string>


class item
{
private:
    std::string itemname;
    std::string category;
    int price;

public:

    /// <<<<<< Default
    item() : itemname("Unnamed"), category("Uncategorized"), price(0) {}


    /// <<<<<<< Constructor
    item(const std::string& itemName, const std::string& category, int price)
            : itemname(itemName), category(category), price(price) {}

    /// <<<<<<<<<<<< Setters
    void setItemName(const std::string& itemName) {
        itemname = itemName;
    }

    void setCategory(const std::string& newCategory) {
        category = newCategory;
    }

    void setPrice(int newPrice) {
        price = newPrice;
    }

    /// <<<<<<<<<< Getters
    std::string getItemName() const {
        return itemname;
    }

    std::string getCategory() const {
        return category;
    }

    int getPrice() const {
        return price;
    }


    /// <<<<<<< Overloading the << operator for cout
    friend std::ostream& operator<<(std::ostream& os, const item& obj)
    {
        os << "Item Name: " << obj.itemname << '\n';
        os << "Category: " << obj.category << '\n';
        os << "Price: " << obj.price << '\n';
        return os;
    }

    bool operator==(const item& other) const {
        return (itemname == other.itemname &&
                category == other.category &&
                price == other.price);
    }



};

struct ComparatorbyPrice {
    bool operator()(const item &a, const item &b) const {
        return a.getPrice() < b.getPrice();
    }
};

struct ComparatorbyName {
    bool operator()(const item &a, const item &b) const {
        return a.getItemName() < b.getItemName();
    }
};

struct ComparatorbyCategory {
    bool operator()(const item &a, const item &b) const {
        return a.getCategory() < b.getCategory();
    }
};


#endif //_ITEM_CLASS_H
