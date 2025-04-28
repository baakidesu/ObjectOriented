#include <stdio.h>
#include <iostream>

class Textile {
private:
    std::string textileType;
    float textileLength = 0;

    public:
    Textile(std::string _textileType, float _textileLength) {
        textileType = _textileType;
        textileLength = _textileLength;
    }

    void printInfo() {
        std::cout <<"Textile Type: " << textileType << " Textile Length: " << textileLength << std::endl;
    }

    int getTextileLength() {
        return textileLength;
    }

    std::string getTextileType() {
        return textileType;
    }
    virtual int calculatePrice() = 0;

};

class Drapery : public Textile {
private:
    float widthOfDrapery, lengthOfDrapery;

    public:
    Drapery(std::string _textileType, float _textileLength): Textile(_textileType, _textileLength) {
        lengthOfDrapery = 1.1f;
        widthOfDrapery = lengthOfDrapery;

    }

    int calculatePrice() override {
        return widthOfDrapery * 7;
    }

    int getLengthOfDraper() {
        return lengthOfDrapery;
    }

    int getWidthOfDraper() {
        return widthOfDrapery;
    }
};

class Upholstery: public Textile {
    private:
    int numberOfWidths;
    float* widths = new float[numberOfWidths];

    public:
    Upholstery(std::string _textileType, int _numberOfWidths, float* _widths): Textile(_textileType, 2) {
        numberOfWidths = _numberOfWidths;
        widths = _widths;
    }

    int calculatePrice() override {
        int totalPrice = 0;
        for (int i = 0; i < numberOfWidths; i++) {
            if (widths[i] < 1) {
                totalPrice += 10;
            }
            if (widths[i] >= 1 && widths[i] <= 4) {
                totalPrice += 25;
            }
            if (widths[i] > 4) {
                totalPrice += 60;
            }
        }
        return totalPrice;
    }

    int getNumberOfWidths() {
        return numberOfWidths;
    }

    int getTotalWidthOfDraper() {
        int totalWidth = 0;
        for (int i = 0; i < numberOfWidths; i++) {
            totalWidth += widths[i];
        }
        return totalWidth;
    }

    int getLengthOfDraper() {
        return 2;
    }
};

void OrderTextile(Textile* t, int sizeOfCoach) {
    int totalArea = 0;
    int price = 0;
    if (Drapery* d = dynamic_cast<Drapery*>(t)) {
        totalArea = d->getLengthOfDraper() * d->getWidthOfDraper();
        price = d->calculatePrice();
    } else if (Upholstery* u = dynamic_cast<Upholstery*>(t)) {
        totalArea = u->getLengthOfDraper() * u->getTotalWidthOfDraper();
        price = u->calculatePrice();
    }

    if (totalArea > sizeOfCoach) {
        std::cout << "Order is complete. Total Price: " << price << std::endl;
    }else {
        std::cout << "You need " << sizeOfCoach << " more m^2 Drapery/Upholstery."<< std::endl;
    }
}

int main() {

    int sizeof_Couch = 25;

    Drapery a("Calico", 5.3f);

    Drapery *b = new Drapery("Satin", 4.7f);

    float sizes[] = { 3.4f, 1.6f, 6.1f };

    Upholstery *c = new Upholstery("Chenille", 3, sizes);

    OrderTextile(b, sizeof_Couch);
}
